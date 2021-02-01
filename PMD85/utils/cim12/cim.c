//-----------------------------------------------------------------------------
#define stricmp strcasecmp
//---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
//-----------------------------------------------------------------------------
#include "cim.h"
//-----------------------------------------------------------------------------
static inline void strupr(char * x) {
  char * uptr = x;
  while ((*uptr = toupper(*uptr))) uptr++;
}

static FILE *fImage = NULL;
static FILE *fFile = NULL;
static int fileLength;
static DWORD oper;

static BYTE buffer[BUFFER_SIZE];

static FILE_NAME_ATTR fna;
static BOOL hasWildcard;
static char cpmFileMask[11];

static int cpmFindPosition;
static char cpmFindMask[11];
static char usr = -1;

static char exeName[MAX_FILE_LEN];
static char exePath[MAX_FILE_LEN];
static char imageName[MAX_FILE_LEN];
static char imagePath[MAX_PATH_LEN];
static char imageExt[MAX_EXT_LEN];
static char filePath[MAX_PATH_LEN];
static char fileName[MAX_FILE_LEN];
static char fileMask[MAX_FILE_LEN];

// disk parameters
static int sectorsPerTrack;
static int *xlt = NULL;
static int allocationUnitSize;
static int allocationUnits;
static int allocVectorSize;
static int recordsPerAU;
static BYTE *au = NULL;
static int extentsPerDirEntry;
static int auPerDirEntry;
static int dirEntries;
static FCB *dir = NULL;
static int systemTracks;
static int systemSize;
static int totalDiskSize;
static int trackSize;
static int retVal;

//-----------------------------------------------------------------------------
int main (int argc, char* argv[]) {
  BOOL writeDir = FALSE;

  printf ("\n%s v%d.%d", XNAME, XVERSION / 16, XVERSION % 16);
  printf ("\n%s\n\n", XAUTHOR);

  retVal = 0;
  do {
    if (PrepareParams (argc, argv) == FALSE) {
      Usage();
      retVal = 1;
      break;
    }

    retVal = ReadConfig (imageExt);
    if (retVal != NO_ERR) {
      PrintError (retVal);
      break;
    }

    // opening/creating image
    if (OpenImage ( (oper & (OP_ADD_FILE | OP_CREATE)) != 0) == FALSE)
      break;

    // creating boot
    if (oper & (OP_CREATE | OP_FORMAT)) {
      if (WriteBoot (TRUE) == FALSE)
        break;
    }

    // Quick format - clean directory entries only
    if (oper & (OP_FORMAT | OP_QUICK)) {
      if (CleanDirectory() == FALSE)
        break;
    }

    // reading directory
    if (ReadDirectory() == FALSE)
      break;

    // checking source/destination file name
    if (! ( (oper & (OP_FORMAT | OP_QUICK)) && ! (oper & OP_ADD_FILE))) {
      if (CheckFileName (cpmFileMask, fileMask) == FALSE) {
        strcpy (fileName, fileMask);
        PrintError (ERR_BAD_FILE_NAME);
        break;
      }
    }

    if (oper & OP_CATALOGUE)          // printing catalogue of image
      Catalogue();
    else if (oper & OP_ADD_FILE) {    // adding file(s)
      AddFiles();
      writeDir = TRUE;
    } else if (oper & OP_ERASE_FILE) { // deleting file(s)
      EraseFiles();
      writeDir = TRUE;
    } else if (oper & OP_EXTRACT_FILE) // extracting file(s)
      ExtractFiles();
    else if (oper & OP_HEX_DUMP)      // print hex dump of the file
      HexDump();
    else if (oper & OP_ASCII_DUMP)    // print content of the file
      AsciiDump();
    else if (oper & OP_WRITE_SYS)    // write system to the image
      WriteSys();
    else if (oper & OP_COPY_SYS)     // copy system to the image from another image
      CopySys();
    else if (oper & OP_EXTRACT_SYS)  // extract system from the image to the file
      ExtractSys();

    retVal = 0;
  } while (FALSE);

  if (writeDir == TRUE) {
    if (WriteDirectory() == FALSE)
      PrintError (ERR_WRITE_IMAGE);
  }

  CloseImage();

  free (xlt);
  xlt = NULL;
  free (au);
  au = NULL;
  free (dir);
  dir = NULL;

  return retVal;
}
//-----------------------------------------------------------------------------
// Helper functions
//-----------------------------------------------------------------------------
void PrepareNameAttr (int de) {
  int ii, jj;

  fna.user = dir[de].un;

  for (ii = 0; ii < 8; ii++) {
    if (dir[de].fn[ii] == ' ')
      break;
    fna.fn[ii] = (dir[de].fn[ii] & 127);
  }
  if (ii == 0) {
    fna.fn[0] = ' ';
    ii++;
  }

  if ( (dir[de].ft[0] & 127) != ' ') {
    fna.fn[ii++] = '.';
    for (jj = 0; jj < 3; jj++) {
      if ( (dir[de].ft[jj] & 127) == ' ')
        break;
      fna.fn[ii++] = (dir[de].ft[jj] & 127);
    }
  }

  fna.fn[ii] = '\0';
  strupr (fna.fn);

  if (dir[de].ft[0] & 0x80)
    fna.rdonly = TRUE;
  else
    fna.rdonly = FALSE;

  if (dir[de].ft[1] & 0x80)
    fna.hidden = TRUE;
  else
    fna.hidden = FALSE;
}
//-----------------------------------------------------------------------------
void PrepareWildcard (char *dest, const char *src, int max) {
  int cnt = 0;

  while (cnt < max) {
    if (src == NULL || *src == '\0')
      dest[cnt] = ' ';
    else if (*src == '*')
      dest[cnt] = '?';
    else
      dest[cnt] = *src++;
    cnt++;
  }
  dest[cnt] = '\0';
}
//-----------------------------------------------------------------------------
BOOL CheckFileName (char *mask, const char *fn) {
  char *p, c;
  char fnx[13], name[9], ext[4];
  int nlen, ii;
  BOOL space;

  nlen = strlen (fn);
  if (nlen == 0 || nlen > 12)
    return FALSE;
  strcpy (fnx, fn);
  strupr (fnx);

  p = strrchr (fnx, '.');
  if (p != NULL) {
    *p = 0;
    p++;
    if (strlen (p) > 3)
      return FALSE;
  }
  PrepareWildcard (ext, p, 3);

  nlen = strlen (fnx);
  if (nlen == 0 || nlen > 8)
    return FALSE;
  PrepareWildcard (name, fnx, 8);

  memcpy (fnx, name, 8);
  fnx[8] = '.';
  memcpy (fnx + 9, ext, 3);
  fnx[12] = 0;

  space = FALSE;
  for (ii = 0; ii < 12; ii++) {
    if (ii == 8)
      continue;

    c = fnx[ii];
    if (c < ' ' || c > '~')
      return FALSE;
    if (c == ' ') {
      if (mask != NULL && ii == 0)
        return FALSE;
      space = TRUE;
    } else if (space == TRUE && ii < 8)
      return FALSE;

    if (mask != NULL) {
      if (c == '<' || c == '>' || c == '.' || c == ',' || c == ';' || c == '"'
          || c == ':' || c == '=' || c == '[' || c == ']' || c == '%'
          || c == '|' || c == '(' || c == ')' || c == '/' || c == '\\')
        return FALSE;
    }

    if (mask == NULL && (c == '?' || c == '*'))
      return FALSE;
  }

  if (mask != NULL) {
    memcpy (mask, name, 8);
    memcpy (mask + 8, ext, 3);

    hasWildcard = (strchr (mask, '?') == NULL) ? FALSE : TRUE;
  }

  return TRUE;
}
//-----------------------------------------------------------------------------
BOOL MarkAU (int auNum, BOOL state) {
  if (auNum >= allocationUnits)
    return FALSE;

  if (state == TRUE)
    au[auNum / 8] |= (1 << (7 - (auNum & 7)));
  else
    au[auNum / 8] &= ~ (1 << (7 - (auNum & 7)));

  return TRUE;
}
//-----------------------------------------------------------------------------
int FindFirstFreeAU (void) {
  int ii, jj, rol;

  for (ii = 0; ii < allocVectorSize; ii++) {
    rol = 0x80;
    for (jj = 0; jj < 8; jj++) {
      if ( (au[ii] & rol) == 0)
        return (ii * 8 + jj);
      rol >>= 1;
    }
  }

  return allocationUnits;
}
//-----------------------------------------------------------------------------
int GetFreeAuCount (void) {
  int ii, jj, rol;
  int freeAU, auNum;

  freeAU = 0;
  auNum = 0;
  for (ii = 0; ii < allocVectorSize && auNum < allocationUnits; ii++) {
    rol = 0x80;
    for (jj = 0; jj < 8 && auNum < allocationUnits; jj++) {
      if ( (au[ii] & rol) == 0)
        freeAU++;
      rol >>= 1;
      auNum++;
    }
  }

  return freeAU;
}
//-----------------------------------------------------------------------------
int GetFreeDirEntriesCount (void) {
  int cnt = 0, xx;

  for (xx = 0; xx < dirEntries; xx++) {
    if (dir[xx].un == FILL_BYTE)
      cnt++;
  }

  return cnt;
}
//-----------------------------------------------------------------------------
int FindFreeDirEntry() {
  int xx;

  for (xx = 0; xx < dirEntries; xx++) {
    if (dir[xx].un == FILL_BYTE)
      return xx;
  }

  return -1;
}
//-----------------------------------------------------------------------------
int FindDirEntry (char *ent, int from) {
  int xx;

  for (xx = from; xx < dirEntries; xx++) {
    if (memcmp (ent, &dir[xx].un, 12) == 0)
      return xx;
  }

  return -1;
}
//-----------------------------------------------------------------------------
int CalcFileRecs (char *ent) {
  int recs = 0;
  int from = 0;
  int ext;

  // go through all directory entries of the file
  // last directory entry of the file gives a final value
  while (TRUE) {
    from = FindDirEntry (ent, from);
    if (from < 0)
      break;

    ext = (dir[from].ex & 0x1F) | ( (dir[from].s2 & 0x7F) << 5);
    recs = ext * RECORDS_PER_EXTENT + dir[from].rc;

    from++;
  }

  return recs;
}
//-----------------------------------------------------------------------------
int CpmFindFirstFile (char *cpmMask) {
  memcpy (cpmFindMask, cpmMask, 11);
  cpmFindPosition = 0;

  return CpmFindNextFile();
}
//-----------------------------------------------------------------------------
int CpmFindNextFile (void) {
  int ii, jj;
  char *p;

  for (ii = cpmFindPosition; ii < dirEntries; ii++) {
    if (dir[ii].un == FILL_BYTE || dir[ii].ex >= extentsPerDirEntry)
      continue;
    if (usr != -1 && usr != dir[ii].un)
      continue;

    p = dir[ii].fn;
    for (jj = 0; jj < 11; jj++) {
      if (cpmFindMask[jj] == '?')
        continue;
      if (cpmFindMask[jj] != (p[jj] & 0x7F))
        break;
    }
    if (jj == 11) {
      cpmFindPosition = ii + 1;
      return ii;
    }
  }

  cpmFindPosition = dirEntries;

  return -1;
}
//-----------------------------------------------------------------------------
BOOL ComputeTrackSector (int au, int rec, int *t, int *s) {
  int totRec;

  if (au >= allocationUnits || rec >= recordsPerAU)
    return FALSE;

  totRec = au * recordsPerAU + rec;
  *s = totRec % sectorsPerTrack;
  *t = totRec / sectorsPerTrack + systemTracks;

  return TRUE;
}
//-----------------------------------------------------------------------------
// Operations itself
//-----------------------------------------------------------------------------
void AddFiles (void) {
  int idx, fcnt, aucnt, trc;
  int jj, t, s;
  int len;
  int fau;
  char fn[MAX_PATH_LEN];
  struct dirent *dent;
  DIR *xdir;
  char mask[11];

  strcpy (fn, filePath);
  strcat (fn, fileMask);

  printf ("Adding file(s) to '%s'\n  path: '%s', mask: '%s'\n\n", imageName, filePath, fileMask);

  xdir = opendir (filePath);
  if (xdir == NULL || CheckFileName (mask, fileMask) == FALSE) {
    printf ("\nPath or file/mask '%s' is invalid!!!\n\n", fn);
    return;
  }

  idx = 0;
  fcnt = 0;

  while ( (dent = readdir (xdir)) != NULL) {
    if (dent->d_type != DT_REG && dent->d_type != DT_LNK)
      continue;
    strcpy (fileName, dent->d_name);

    if (CheckFileName (cpmFileMask, fileName) == FALSE) {
      PrintError (ERR_BAD_FILE_NAME);
      continue;
    }

    for (jj = 0; jj < 11; jj++) {
      if (mask[jj] == '?')
        continue;
      if (mask[jj] != cpmFileMask[jj]) {
        jj = -1;
        break;
      }
    }
    if (jj < 0)
      continue;

    // check for existence of the file with this name on the image
    if (CpmFindFirstFile (cpmFileMask) >= 0) {
      PrintError (ERR_FILE_EXIST);
      continue;
    }

    // open file that should be added to the image
    if (OpenCurrentFile (FALSE) == FALSE) {
      CloseCurrentFile();
      continue;
    }

    // check file size
    if (fileLength > MAX_CPM_FILE_SIZE) {
      PrintError (ERR_FILE_TOO_LONG);
      CloseCurrentFile();
      continue;
    }

    // check number of directory entries that will be occupied by file
    if ( ( (fileLength + EXTENT_SIZE * extentsPerDirEntry - 1) / (EXTENT_SIZE * extentsPerDirEntry)) > GetFreeDirEntriesCount()) {
      PrintError (ERR_DIRECTORY_FULL);
      break;
    }

    // check number of allocation units that file needs
    if ( ( (fileLength + allocationUnitSize - 1) / allocationUnitSize) > GetFreeAuCount()) {
      PrintError (ERR_DISK_FULL);
      break;
    }

    // compute total records
    trc = (fileLength + RECORD_SIZE - 1) / RECORD_SIZE;

    aucnt = 0;
    do {
      if ( (aucnt % auPerDirEntry) == 0) {
        if (aucnt > 0) {
          jj = (aucnt - 1) / (auPerDirEntry / extentsPerDirEntry);
          dir[idx].ex = (jj & 0x1F);
          if (jj > 0x1F)
            dir[idx].s2 = ( (jj >> 5) & 0x7F);
          dir[idx].rc = 128;
        }
        idx = FindFreeDirEntry();
        memset (&dir[idx], 0, sizeof (FCB));
        if (usr == -1)
          dir[idx].un = 0;
        else
          dir[idx].un = usr;
        memcpy (dir[idx].fn, cpmFileMask, 11);
      }

      if (fileLength == 0) // for zero file length
        break;

      fau = FindFirstFreeAU();
      MarkAU (fau, TRUE);
      if (auPerDirEntry == 16)
        dir[idx].au[aucnt % 16] = (BYTE) fau;
      else
        memcpy (&dir[idx].au[ (aucnt % 8) * 2], &fau, 2);
      //*(WORD *)&dir[idx].au[(aucnt % 8) * 2] = (WORD)fau;

      memset (buffer, FILL_BYTE, BUFFER_SIZE);
      len = (fileLength > allocationUnitSize) ? allocationUnitSize : fileLength;
      if (fread (buffer, len, 1, fFile) != 1) {
        PrintError (ERR_READ_FILE);
        return;
      }

      for (jj = 0; jj < recordsPerAU; jj++) {
        if (ComputeTrackSector (fau, jj, &t, &s) == FALSE) {
          PrintError (ERR_FATAL_ERROR);
          return;
        }
        if (WriteSector (buffer + jj * RECORD_SIZE, t, s) == FALSE) {
          PrintError (ERR_WRITE_IMAGE);
          return;
        }
      }

      aucnt++;
      fileLength -= len;
    } while (fileLength > 0);

    if (aucnt > 0) {  // close last extent of the file with no zero length
      jj = (aucnt - 1) / (auPerDirEntry / extentsPerDirEntry);
      dir[idx].ex = (jj & 0x1F);
      if (jj > 0x1F)
        dir[idx].s2 = ( (jj >> 5) & 0x7F);
      dir[idx].rc = trc % 128;
      if (dir[idx].rc == 0 && trc > 0)
        dir[idx].rc = 128;
    }

    CloseCurrentFile();
    fcnt++;

    printf ("File '%s' added\n", fileName);

  }
  closedir (xdir);

  printf ("\nDone. %d file(s) added.\n\n", fcnt);
}
//-----------------------------------------------------------------------------
void EraseFiles() {
  char entry[13];
  int idx, idx2, cnt;

  if (CheckFileName (cpmFileMask, fileMask) == FALSE) {
    strcpy (fileName, fileMask);
    PrintError (ERR_BAD_FILE_NAME);
    return;
  }

  printf ("Erasing file(s) from '%s', mask: '%s'\n\n", imageName, fileMask);

  cnt = 0;
  idx = CpmFindFirstFile (cpmFileMask);
  while (idx >= 0) {
    memcpy (entry, &dir[idx].un, 12);
    dir[idx].un = FILL_BYTE;
    idx2 = idx + 1;
    while ( (idx2 = FindDirEntry (entry, idx2)) >= 0)
      dir[idx2++].un = FILL_BYTE;
    cnt++;

    memcpy (entry, &dir[idx].fn, 8);
    entry[8] = 0;
    trimRight (entry);
    strcat (entry, ".");
    idx2 = strlen (entry);
    memcpy (entry + idx2, &dir[idx].ft, 3);
    entry[idx2 + 3] = 0;
    trimRight (entry);
    printf ("File '%s' eresed\n", entry);

    idx = CpmFindNextFile();
  }

  printf ("\nDone. %d file(s) erased.\n\n", cnt);
}
//-----------------------------------------------------------------------------
void ExtractFiles() {
  char entry[12], c;
  int idx, idx2, cnt, ii, jj, fau, t, s;

  if (CheckFileName (cpmFileMask, fileMask) == FALSE) {
    strcpy (fileName, fileMask);
    PrintError (ERR_BAD_FILE_NAME);
    return;
  }

  printf ("Extracting file(s) from '%s'\n  path: '%s', mask: '%s'\n\n", imageName, filePath, fileMask);

  cnt = 0;
  idx = CpmFindFirstFile (cpmFileMask);
  while (idx >= 0) {
    memcpy (entry, &dir[idx].un, 12);
    PrepareNameAttr (idx);
    fna.totrc = CalcFileRecs (entry);
    idx2 = idx;

    strcpy (fileName, fna.fn);
    for (ii = strlen (fileName) - 1; ii >= 0; ii--) {
      c = fileName[ii];
      if (c == '\\' || c == '/' || c == '"' || c == '|')
        fileName[ii] = '_';
    }
    if (OpenCurrentFile (TRUE) == FALSE)
      return;

    do {
      for (ii = 0; ii < 16; ii++) {
        if (auPerDirEntry == 8) {
          fau = 0;
          memcpy (&fau, &dir[idx2].au[ii++], 2);
          //fau = *(WORD *)&dir[idx2].au[ii++];
        } else
          fau = dir[idx2].au[ii];
        if (fau == 0)
          break;

        for (jj = 0; jj < recordsPerAU && fna.totrc > 0; jj++) {
          if (ComputeTrackSector (fau, jj, &t, &s) == FALSE) {
            PrintError (ERR_FATAL_ERROR);
            return;
          }
          if (ReadSector (buffer, t, s) == FALSE) {
            PrintError (ERR_READ_IMAGE);
            return;
          }
          if (fwrite (buffer, RECORD_SIZE, 1, fFile) != 1) {
            PrintError (ERR_WRITE_FILE);
            return;
          }
          fna.totrc--;
        }
      }
    } while ( (idx2 = FindDirEntry (entry, ++idx2)) >= 0);

    CloseCurrentFile();
    cnt++;

    if (strcmp (fileName, fna.fn) == 0)
      printf ("File '%s' extracted\n", fileName);
    else
      printf ("File '%s' extracted as %s\n", fna.fn, fileName);

    idx = CpmFindNextFile();
  }

  if (cnt == 0 && hasWildcard == FALSE) {
    strcpy (fileName, fileMask);
    PrintError (ERR_FILE_NOT_EXIST);
  } else
    printf ("\nDone. %d file(s) extracted.\n\n", cnt);
}
//-----------------------------------------------------------------------------
void Catalogue (void) {
  int ii, jj, files, total, idx;
  int *sort;
  FILE_NAME_ATTR *dirfiles;

  if (CheckFileName (cpmFileMask, fileMask) == FALSE) {
    strcpy (fileName, fileMask);
    PrintError (ERR_BAD_FILE_NAME);
    return;
  }

  sort = (int *) malloc (dirEntries * sizeof (int));
  dirfiles = (FILE_NAME_ATTR *) malloc (dirEntries * sizeof (FILE_NAME_ATTR));

  printf ("Catalogue of '%s', mask: '%s'\n\n", imageName, fileMask);
  printf (" U Name          RECS  SIZE  RH\t U Name          RECS  SIZE  RH\n");
  printf ("-------------------------------\t-------------------------------\n");

  files = 0;
  total = 0;

  idx = CpmFindFirstFile (cpmFileMask);
  while (idx >= 0) {
    PrepareNameAttr (idx);
    fna.totrc = CalcFileRecs (&dir[idx].un);
    fna.size = (fna.totrc + recordsPerAU - 1)
               / recordsPerAU * (allocationUnitSize / 1024);
    memcpy ( (char *) &dirfiles[files], (char *) &fna, sizeof (FILE_NAME_ATTR));

    for (jj = 0; jj < files; jj++) {
      if (strcmp (fna.fn, dirfiles[sort[jj]].fn) < 0)
        break;
    }
    for (ii = files; ii > jj; ii--)
      sort[ii] = sort[ii - 1];
    sort[jj] = files;

    files++;
    total += fna.size;

    idx = CpmFindNextFile();
  }

  for (ii = 0; ii < files; ii++) {
    jj = sort[ii];

    while (strlen (dirfiles[jj].fn) < 12)
      strcat (dirfiles[jj].fn, " ");

    printf ("%2d %s  %4d %4dK  %c%c",
            dirfiles[jj].user, dirfiles[jj].fn,
            dirfiles[jj].totrc, dirfiles[jj].size,
            (dirfiles[jj].rdonly == TRUE) ? 'R' : '-',
            (dirfiles[jj].hidden == TRUE) ? 'H' : '-');
    if (ii % 2)
      printf ("\n");
    else
      printf ("\t");

    if ( ( (ii + 1) % 32) == 0) {
      printf ("Press Enter to continue...");
      while (getchar() != '\n')
        ;
      printf ("\r");
    }
  }

  if (files % 2)
    printf ("\n");
  printf ("\n");

  printf ("%dK in %d file(s), %dK free\n\n", total, files, GetFreeAuCount() * (allocationUnitSize / 1024));

  free (sort);
  free (dirfiles);
}
//-----------------------------------------------------------------------------
void AsciiDump (void) {
  char entry[12], c;
  int idx, ii, jj, kk, fau, t, s;

  if (strchr (cpmFileMask, '?') != NULL) {
    printf ("File name '%s' must be unambiguous!\n\n", fileMask);
    return;
  }

  printf ("Content of the file '%s' from '%s'\n\n", fileMask, imageName);

  idx = CpmFindFirstFile (cpmFileMask);
  if (idx < 0) {
    printf ("File '%s' not found\n\n", fileMask);
    return;
  } else {
    memcpy (entry, &dir[idx].un, 12);
    PrepareNameAttr (idx);
    fna.totrc = CalcFileRecs (entry);

    do {
      for (ii = 0; ii < 16; ii++) {
        if (auPerDirEntry == 8) {
          fau = 0;
          memcpy (&fau, &dir[idx].au[ii++], 2);
          //fau = *(WORD *)&dir[idx].au[ii++];
        } else
          fau = dir[idx].au[ii];
        if (fau == 0)
          break;

        for (jj = 0; jj < recordsPerAU && fna.totrc > 0; jj++) {
          if (ComputeTrackSector (fau, jj, &t, &s) == FALSE) {
            PrintError (ERR_FATAL_ERROR);
            return;
          }
          if (ReadSector (buffer, t, s) == FALSE) {
            PrintError (ERR_READ_IMAGE);
            return;
          }

          for (kk = 0; kk < RECORD_SIZE; kk++) {
            c = (char) buffer[kk];
            if (c == 0x1A)  // EOF
              break;
            printf ("%c", c);
          }

          fna.totrc--;
        }
      }
    } while ( (idx = FindDirEntry (entry, ++idx)) >= 0);

    printf ("\n\n");
  }
}
//-----------------------------------------------------------------------------
void HexDump (void) {
  char entry[12], c;
  int idx, ii, jj, kk, ll, fau, t, s, adr;

  if (strchr (cpmFileMask, '?') != NULL) {
    printf ("File name '%s' must be unambiguous!\n\n", fileMask);
    return;
  }

  printf ("Hex Dump of the file '%s' from '%s'\n\n", fileMask, imageName);

  idx = CpmFindFirstFile (cpmFileMask);
  if (idx < 0) {
    printf ("File '%s' not found\n\n", fileMask);
    return;
  } else {
    memcpy (entry, &dir[idx].un, 12);
    PrepareNameAttr (idx);
    fna.totrc = CalcFileRecs (entry);

    adr = 0;
    do {
      for (ii = 0; ii < 16; ii++) {
        if (auPerDirEntry == 8) {
          fau = 0;
          memcpy (&fau, &dir[idx].au[ii++], 2);
          // fau = *(WORD *)&dir[idx].au[ii++];
        } else
          fau = dir[idx].au[ii];
        if (fau == 0)
          break;

        for (jj = 0; jj < recordsPerAU && fna.totrc > 0; jj++) {
          if (ComputeTrackSector (fau, jj, &t, &s) == FALSE) {
            PrintError (ERR_FATAL_ERROR);
            return;
          }
          if (ReadSector (buffer, t, s) == FALSE) {
            PrintError (ERR_READ_IMAGE);
            return;
          }

          for (kk = 0; kk < RECORD_SIZE; kk += 16) {
            printf ("%06X  ", adr);
            for (ll = 0; ll < 16; ll++)
              printf ("%02X ", buffer[kk + ll]);
            printf (" ");
            for (ll = 0; ll < 16; ll++) {
              c = buffer[kk + ll];
              if (c < 32 || c == 127)
                c = '.';
              printf ("%c", c);
            }
            printf ("\n");

            adr += 16;
          }

          fna.totrc--;
        }
      }
    } while ( (idx = FindDirEntry (entry, ++idx)) >= 0);

    printf ("\n\n");
  }
}
//-----------------------------------------------------------------------------
void WriteSys (void) {
  int len;

  if (systemSize == 0) {
    PrintError (ERR_IMG_NO_SYS);
    return;
  }

  strcpy (fileName, fileMask);
  if (OpenCurrentFile (FALSE) == FALSE)
    return;

  if (fileLength > systemSize) {
    CloseCurrentFile();
    PrintError (ERR_IMG_SYS_TOO_LONG);
    return;
  }

  fseek (fFile, 0L, SEEK_SET);
  fseek (fImage, 0L, SEEK_SET);
  while (fileLength > 0) {
    len = (fileLength > BUFFER_SIZE) ? BUFFER_SIZE : fileLength;
    if (fread (buffer, len, 1, fFile) != 1) {
      PrintError (ERR_READ_FILE);
      return;
    }

    if (fwrite (buffer, len, 1, fImage) != 1) {
      PrintError (ERR_WRITE_IMAGE);
      return;
    }
    fileLength -= len;
  }

  CloseCurrentFile();

  printf ("\nDone. System written.\n\n");
}
//-----------------------------------------------------------------------------
void CopySys (void) {
  int len;
  char *p;

  if (systemSize == 0) {
    PrintError (ERR_IMG_NO_SYS);
    return;
  }

  strcpy (fileName, fileMask);
  p = strrchr (fileName, '.');
  if (p == NULL || strcmp (p + 1, imageExt) != 0) {
    CloseCurrentFile();
    PrintError (ERR_IMG_BAD_TYPE);
    return;
  }

  if (OpenCurrentFile (FALSE) == FALSE)
    return;

  fseek (fFile, 0L, SEEK_SET);
  fseek (fImage, 0L, SEEK_SET);
  while (systemSize > 0) {
    len = (systemSize > BUFFER_SIZE) ? BUFFER_SIZE : systemSize;
    if (fread (buffer, len, 1, fFile) != 1) {
      PrintError (ERR_READ_FILE);
      return;
    }

    if (fwrite (buffer, len, 1, fImage) != 1) {
      PrintError (ERR_WRITE_IMAGE);
      return;
    }
    systemSize -= len;
  }

  CloseCurrentFile();

  printf ("\nDone. System copied.\n\n");
}
//-----------------------------------------------------------------------------
void ExtractSys (void) {
  int len;

  if (systemSize == 0) {
    PrintError (ERR_IMG_NO_SYS);
    return;
  }

  strcpy (fileName, fileMask);
  if (OpenCurrentFile (TRUE) == FALSE)
    return;

  fileLength = systemSize;

  fseek (fFile, 0L, SEEK_SET);
  fseek (fImage, 0L, SEEK_SET);
  while (fileLength > 0) {
    len = (fileLength > BUFFER_SIZE) ? BUFFER_SIZE : fileLength;
    if (fread (buffer, len, 1, fImage) != 1) {
      PrintError (ERR_READ_IMAGE);
      return;
    }

    if (fwrite (buffer, len, 1, fFile) != 1) {
      PrintError (ERR_WRITE_FILE);
      return;
    }
    fileLength -= len;
  }

  CloseCurrentFile();

  printf ("\nDone. System extracted.\n\n");
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BOOL ReadDirectory() {
  int ii, jj, t, s;
  int dirAU = (dirEntries * DIR_ENTRY_SIZE) / allocationUnitSize;
  WORD w;

  for (ii = 0; ii < dirAU; ii++) {
    for (jj = 0; jj < recordsPerAU; jj++) {
      if (ComputeTrackSector (ii, jj, &t, &s) == FALSE)
        return FALSE;
      if (ReadSector ( (BYTE *) &dir[ii * recordsPerAU * DIR_ENTRIES_PER_RECORD + jj * DIR_ENTRIES_PER_RECORD], t, s) == FALSE)
        return FALSE;
    }
  }

  // unmark all allocation units
  for (ii = 0; ii < allocVectorSize; ii++)
    au[ii] = 0;

  // mark allocation units occupied by directory itself
  for (ii = 0; ii < dirAU; ii++)
    MarkAU (ii, TRUE);

  // mark allocation units occupied by files
  for (ii = 0; ii < dirEntries; ii++) {
    if (dir[ii].un == FILL_BYTE)
      continue;

    PrepareNameAttr (ii);
    if (CheckFileName (NULL, fna.fn) == FALSE) {
      PrintError (ERR_DIR_ENTRY);
      return FALSE;
    }

    if (auPerDirEntry == 8) {
      // allocation units numbers are WORDs
      for (jj = 0; jj < 16; jj += 2) {
        memcpy (&w, &dir[ii].au[jj], 2);
        //w = *(WORD *)(&dir[ii].au[jj]);
        if (w == 0)
          break;
        if (MarkAU (w, TRUE) == FALSE) {
          PrintError (ERR_DIR_ENTRY);
          return FALSE;
        }
      }
    } else {
      // allocation units numbers are BYTEs
      for (jj = 0; jj < 16; jj++) {
        if (dir[ii].au[jj] == 0)
          break;
        if (MarkAU (dir[ii].au[jj], TRUE) == FALSE) {
          PrintError (ERR_DIR_ENTRY);
          return FALSE;
        }
      }
    }
  }

  return TRUE;
}
//-----------------------------------------------------------------------------
BOOL WriteDirectory (void) {
  int ii, jj, t, s;
  int dirAU = (dirEntries * DIR_ENTRY_SIZE) / allocationUnitSize;

  for (ii = 0; ii < dirAU; ii++) {
    for (jj = 0; jj < recordsPerAU; jj++) {
      if (ComputeTrackSector (ii, jj, &t, &s) == FALSE)
        return FALSE;
      if (WriteSector ( (BYTE *) &dir[ii * recordsPerAU * DIR_ENTRIES_PER_RECORD + jj * DIR_ENTRIES_PER_RECORD], t, s) == FALSE)
        return FALSE;
    }
  }

  return TRUE;
}
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BOOL OpenCurrentFile (BOOL create) {
  char fn[MAX_PATH_LEN];

  strcpy (fn, filePath);
  strcat (fn, fileName);

  if (create == TRUE) {
    remove (fn); // remove first
    fFile = fopen (fn, "a+b"); // create if not exist
    if (fFile != NULL)
      fclose (fFile);
  }

  fFile = fopen (fn, "r+b");
  if (fFile == NULL) {
    if (create == TRUE)
      PrintError (ERR_CREATE_FILE);
    else
      PrintError (ERR_OPEN_FILE);
    return FALSE;
  }

  if (create == TRUE)
    fileLength = 0;
  else {
    fseek (fFile, 0L, SEEK_END);
    fileLength = ftell (fFile);
  }
  fseek (fFile, 0L, SEEK_SET);

  return TRUE;
}
//-----------------------------------------------------------------------------
void CloseCurrentFile() {
  if (fFile != NULL)
    fclose (fFile);
  fFile = NULL;
}
//---------------------------------------------------------------------------
// Functions for image opening, creating and so on...
//---------------------------------------------------------------------------
BOOL OpenImage (BOOL canCreate) {
  char fn[MAX_PATH_LEN];
  int ii;

  strcpy (fn, imagePath);
  strcat (fn, imageName);

  if (canCreate == TRUE) {
    fImage = fopen (fn, "a+b"); // create if not exist
    if (fImage != NULL)
      fclose (fImage);
  }

  fImage = fopen (fn, "r+b");
  if (fImage == NULL) {
    if (canCreate == TRUE)
      PrintError (ERR_CREATE_IMAGE);
    else
      PrintError (ERR_OPEN_IMAGE);
    return FALSE;
  }

  fseek (fImage, 0L, SEEK_END);
  if (canCreate == TRUE && ftell (fImage) == 0) {
    oper |= OP_CREATE;
    memset (buffer, FILL_BYTE, RECORD_SIZE);

    fseek (fImage, 0L, SEEK_SET);
    for (ii = 0; ii < totalDiskSize; ii += RECORD_SIZE) {
      if (fwrite (buffer, RECORD_SIZE, 1, fImage) != 1) {
        PrintError (ERR_WRITE_IMAGE);
        return FALSE;
      }
    }
    printf ("Image '%s' was created.\n", imageName);
  }

  if (ftell (fImage) != totalDiskSize) {
    PrintError (ERR_IMAGE_SIZE);
    return FALSE;
  }

  return TRUE;
}
//-----------------------------------------------------------------------------
void CloseImage (void) {
  if (fImage != NULL)
    fclose (fImage);
  fImage = NULL;
}
//-----------------------------------------------------------------------------
BOOL WriteBoot (BOOL writeTail) {
  if (systemSize > 0) {
    memset (buffer, FILL_BYTE, RECORD_SIZE);
    *buffer = 0xC9; // instruction RET

    fseek (fImage, 0L, SEEK_SET);
    if (fwrite (buffer, RECORD_SIZE, 1, fImage) != 1) {
      PrintError (ERR_WRITE_IMAGE);
      return FALSE;
    }
  }

  if (writeTail == TRUE) {
    memset (buffer, 0, RECORD_SIZE);
    sprintf ( (char *) buffer, "This disk was formated with '%s v%d.%d' programmed by %s",
              XNAME, XVERSION / 16, XVERSION % 16, XAUTHOR);

    fseek (fImage, totalDiskSize - RECORD_SIZE, SEEK_SET);
    if (fwrite (buffer, RECORD_SIZE, 1, fImage) != 1) {
      PrintError (ERR_WRITE_IMAGE);
      return FALSE;
    }
  }

  printf ("Image '%s' was formated.\n", imageName);

  return TRUE;
}
//---------------------------------------------------------------------------
BOOL ReadSector (BYTE *buf, int track, int sector) {
  int seek = systemSize
             + (track - systemTracks) * trackSize
             + ( (xlt[sector] - 1) * RECORD_SIZE);
  fseek (fImage, seek, SEEK_SET);

  if (fread (buf, RECORD_SIZE, 1, fImage) == 1)
    return TRUE;
  return FALSE;
}
//---------------------------------------------------------------------------
BOOL WriteSector (BYTE *buf, int track, int sector) {
  int seek = systemSize
             + (track - systemTracks) * trackSize
             + ( (xlt[sector] - 1) * RECORD_SIZE);
  fseek (fImage, seek, SEEK_SET);

  if (fwrite (buf, RECORD_SIZE, 1, fImage) == 1)
    return TRUE;
  return FALSE;
}
//---------------------------------------------------------------------------
BOOL CleanDirectory (void) {
  int ii;
  int dirSize = dirEntries * DIR_ENTRY_SIZE;

  fseek (fImage, systemSize, SEEK_SET);
  memset (buffer, FILL_BYTE, RECORD_SIZE);
  for (ii = 0; ii < dirSize; ii += RECORD_SIZE) {
    if (fwrite (buffer, RECORD_SIZE, 1, fImage) != 1) {
      PrintError (ERR_WRITE_IMAGE);
      return FALSE;
    }
  }

  if (oper & OP_QUICK)
    printf ("Directory of image '%s' was cleaned.\n", imageName);

  return TRUE;
}
//---------------------------------------------------------------------------
// Functions for reading of config file.
//---------------------------------------------------------------------------
char* trimLeft (char *in_out) {
  char *p, *q;

  if (isspace (*in_out)) {
    p = in_out;
    while (isspace (*p))
      p++;

    q = in_out;
    while (*p)
      *q++ = *p++;
    *q = 0;
  }

  return in_out;
}
//---------------------------------------------------------------------------
char* trimRight (char *in_out) {
  char *p;

  p = in_out + strlen (in_out);
  while (p > in_out) {
    p--;
    if (isspace (*p))
      *p = 0;
    else
      break;
  }

  return in_out;
}
//---------------------------------------------------------------------------
char* trim (char *in_out) {
  return trimLeft (trimRight (in_out));
}
//---------------------------------------------------------------------------
int parseNumber (char *s) {
  char *p;
  int n = strtol (s, &p, 10);
  if (n < 0 || (n == 0 && *p != 0))
    return -1;
  return n;
}
//---------------------------------------------------------------------------
int ReadConfig (char *ext) {
  char buff[1024];
  char *p, *q;
  FILE *f;
  int e, flg, i, j;

  if (*ext == 0)
    return ERR_IMG_EXT_MISSING;

  strcpy (buff, exePath);
  strcat (buff, exeName);
  strcat (buff, ".ini");
  f = fopen (buff, "r");
  if (f == NULL)
    return ERR_CONF_FILE_MISSING;

  e = NO_ERR;
  while (TRUE) {
    p = fgets (buff, sizeof (buff) - 1, f);
    if (p == NULL) {            // end of file?
      e = ERR_IMG_DEF_MISSING;  // yes
      break;
    }

    trim (p);
    if (*p != '[')  // begin of section?
      continue;     // no
    p++;
    q = strchr (p, ']'); // check end of section name
    if (q == NULL)
      continue;
    *q++ = 0;
    if (*q != 0)
      continue;
    if (stricmp (ext, p) != 0) // check extention of image file
      continue;

    flg = 0;
    sectorsPerTrack = -1;
    while (TRUE) {
      p = fgets (buff, sizeof (buff) - 1, f);
      if (p == NULL)   // end of file?
        break;         // yes
      trim (p);
      if (*p == 0 || *p == ';') // empty line or comment
        continue;
      if (*p == '[')  // next section
        break;
      q = strchr (p, '='); // find value
      if (q == NULL) {
        e = ERR_IMG_DEF_ERROR; // value missing
        break;
      }

      *q++ = 0;     // ending of key
      trimRight (p); // trim key

      trimLeft (q); // trim value
      if (*q == 0) {
        e = ERR_IMG_DEF_ERROR; // value is empty
        break;
      }

      if (strcmp (p, "SPT") == 0) {
        sectorsPerTrack = parseNumber (q);
        if (sectorsPerTrack < 1)
          break; // invalid value
        flg |= PAR_SPT;
      } else if (strcmp (p, "XLT") == 0) {
        if ( (flg & PAR_SPT) == 0)
          break; // SPT must precede XLT
        xlt = (int *) malloc (sectorsPerTrack * sizeof (int));
        if (xlt == NULL) {
          e = ERR_FATAL_ERROR; // not enough space
          break;
        }

        i = (int) strtol (q, &p, 10);
        if (i == 0) {
          if (*p != 0)
            break;
          for (i = 0; i < sectorsPerTrack; i++)
            xlt[i] = i + 1;
        } else {
          for (i = 0; i < sectorsPerTrack; i++) {
            xlt[i] = (int) strtol (q, &p, 10);
            if (xlt[i] < 1 || xlt[i] > sectorsPerTrack)
              break;
            if ( ( (i + 1) == sectorsPerTrack && *p != 0)
                 || ( (i + 1) < sectorsPerTrack && *p != ','))
              break;
            for (j = 0; j < i; j++) {
              if (xlt[j] == xlt[i])
                break;
            }
            if (j < i)
              break;
            q = p + 1;
          }
          if (i < sectorsPerTrack)
            break; // invalid value
        }
        flg |= PAR_XLT;
      } else if (strcmp (p, "BLS") == 0) {
        allocationUnitSize = parseNumber (q);
        if (allocationUnitSize != 1 && allocationUnitSize != 2
            && allocationUnitSize != 4 && allocationUnitSize != 8
            && allocationUnitSize != 16)
          break; // invalid value
        allocationUnitSize *= 1024;
        flg |= PAR_BLS;
      } else if (strcmp (p, "EXM") == 0) {
        extentsPerDirEntry = parseNumber (q);
        if (extentsPerDirEntry != 0 && extentsPerDirEntry != 1
            && extentsPerDirEntry != 3 && extentsPerDirEntry != 7
            && extentsPerDirEntry != 15)
          break; // invalid value
        extentsPerDirEntry++;
        flg |= PAR_EXM;
      } else if (strcmp (p, "DSM") == 0) {
        allocationUnits = parseNumber (q);
        if (allocationUnits < 1 || allocationUnits > 65535)
          break; // invalid value
        allocationUnits++;
        flg |= PAR_DSM;
      } else if (strcmp (p, "DRM") == 0) {
        dirEntries = parseNumber (q) + 1;
        if ( (flg & PAR_BLS) == 0 || dirEntries == 0 || dirEntries > 65536
             || ( (dirEntries * 32) % allocationUnitSize) > 0)
          break; // invalid value
        flg |= PAR_DRM;
      } else if (strcmp (p, "OFF") == 0) {
        systemTracks = parseNumber (q);
        if (systemTracks < 0)
          break; // invalid value
        if ( (flg & PAR_OFFX) == 0) {
          if (sectorsPerTrack < 0)
            break; // invalid value
          systemSize = systemTracks * sectorsPerTrack * RECORD_SIZE;
        }
        flg |= PAR_OFF;
      } else if (strcmp (p, "OFFX") == 0) {
        systemSize = parseNumber (q);
        if (systemSize < 0)
          break; // invalid value
        systemSize = systemSize * RECORD_SIZE;
        flg |= PAR_OFFX;
      }
    }

    break;
  }

  fclose (f);

  if (e == NO_ERR && (flg & PAR_ALL) != PAR_ALL)
    e = ERR_IMG_DEF_ERROR;

  if (e == NO_ERR) {
    trackSize = sectorsPerTrack * RECORD_SIZE;
    totalDiskSize = allocationUnits * allocationUnitSize;
    totalDiskSize = totalDiskSize + trackSize - 1;
    totalDiskSize = (totalDiskSize / trackSize) * trackSize;
    totalDiskSize = totalDiskSize + systemSize;

    if (totalDiskSize > MAX_CPM_DISK_SIZE)
      e = ERR_IMG_DEF_ERROR; // image is too large - bad definition
    else {
      dir = (FCB *) malloc (dirEntries * sizeof (FCB));
      allocVectorSize = (allocationUnits + 7) / 8;
      au = (BYTE *) malloc (allocVectorSize);
      recordsPerAU = allocationUnitSize / RECORD_SIZE;
      auPerDirEntry = (allocationUnits > 256) ? 8 : 16;
    }
  }

#if 0
  printf ("sectorsPerTrack=%d\n", sectorsPerTrack);
  printf ("xlt=");
  for (i = 0; i < sectorsPerTrack; i++) {
    if (i > 0)
      printf (",");
    printf ("%d", xlt[i]);
  }
  printf ("\n");
  printf ("allocationUnitSize=%d\n", allocationUnitSize);
  printf ("extentsPerDirEntry=%d\n", extentsPerDirEntry);
  printf ("allocationUnits=%d\n", allocationUnits);
  printf ("dirEntries=%d\n", dirEntries);
  printf ("systemSize=%d\n", systemSize);
  printf ("trackSize=%d\n", trackSize);
  printf ("totalDiskSize=%d\n", totalDiskSize);
#endif

  return e;
}
//-----------------------------------------------------------------------------
// Functions for preparing command line parameters.
//-----------------------------------------------------------------------------
void ExtractPathName (char *path, char *name, char *ext, const char *src) {
  char *p;

  p = strrchr (src, '/');
  if (p == NULL) {
    strcpy (path, "./");
    strcpy (name, src);
  } else {
    strncpy (path, src, p - src + 1);
    path[p - src + 1] = '\0';
    strcpy (name, p + 1);
  }

  if (ext != NULL) {
    p = strrchr (name, '.');
    if (p == NULL)
      *ext = '\0';
    else
      strcpy (ext, p + 1);
  }
}
//-----------------------------------------------------------------------------
BOOL PrepareParams (int argc, char* argv[]) {
  BOOL waitFile = FALSE;
  BOOL waitNumber = FALSE;
  int ii;
  char *p;

  ExtractPathName (exePath, exeName, NULL, argv[0]);
  p = strrchr (exeName, '.');
  if (p != NULL)
    *p = '\0';

  if (argc == 1)
    return FALSE;

  *filePath = '\0';
  *fileName = '\0';
  *fileMask = '\0';
  usr = -1;
  oper = 0;

  ExtractPathName (imagePath, imageName, imageExt, argv[1]);

  for (ii = 2; ii < argc; ii++) {
    if (waitFile == TRUE) {
      ExtractPathName (filePath, fileMask, NULL, argv[ii]);
      if ( (oper & (OP_ADD_FILE | OP_EXTRACT_FILE | OP_WRITE_SYS | OP_COPY_SYS)) == 0
           && strcmp (filePath, "./") != 0)
        return FALSE;
      waitFile = FALSE;
    } else if (waitNumber == TRUE) {
      usr = parseNumber (argv[ii]);
      if (usr < 0 || usr > 15)
        return FALSE;
      waitNumber = FALSE;
    } else if (argv[ii][0] == '-') {
      if (strlen (argv[ii]) != 2)
        return FALSE;

      switch (argv[ii][1]) {
      case 'c' :
        oper |= OP_CATALOGUE;
        waitFile = TRUE;
        break;

      case 'f' :
        oper |= OP_FORMAT;
        break;

      case 'q' :
        oper |= OP_QUICK;
        break;

      case 'a' :
        oper |= OP_ADD_FILE;
        waitFile = TRUE;
        break;

      case 'e' :
        oper |= OP_ERASE_FILE;
        waitFile = TRUE;
        break;

      case 'x' :
        oper |= OP_EXTRACT_FILE;
        waitFile = TRUE;
        break;

      case 'w' :
        oper |= OP_WRITE_SYS;
        waitFile = TRUE;
        break;

      case 'i' :
        oper |= OP_COPY_SYS;
        waitFile = TRUE;
        break;

      case 's' :
        oper |= OP_EXTRACT_SYS;
        waitFile = TRUE;
        break;

      case 'h' :
        oper |= OP_HEX_DUMP;
        waitFile = TRUE;
        break;

      case 't' :
        oper |= OP_ASCII_DUMP;
        waitFile = TRUE;
        break;

      case 'u' :
        waitNumber = TRUE;
        break;

      default :
        return FALSE;
      }
    } else
      return FALSE;
  }

  if (oper == 0)
    return FALSE;
  if (waitFile == TRUE && ! (oper & OP_CATALOGUE))
    return FALSE;
  if ( (oper & OP_FORMAT) && (oper & OP_QUICK))
    return FALSE;
  if ( (oper & OP_CATALOGUE) && (oper & ~OP_CATALOGUE))
    return FALSE;
  if ( (oper & OP_WRITE_SYS) && (oper & ~OP_WRITE_SYS))
    return FALSE;
  if ( (oper & OP_COPY_SYS) && (oper & ~OP_COPY_SYS))
    return FALSE;
  if ( (oper & OP_EXTRACT_SYS) && (oper & ~OP_EXTRACT_SYS))
    return FALSE;
  if ( (oper & (OP_FORMAT | OP_QUICK | OP_ADD_FILE))
       && (oper & ~ (OP_FORMAT | OP_QUICK | OP_ADD_FILE)))
    return FALSE;
  if ( (oper & OP_ERASE_FILE) && (oper & OP_EXTRACT_FILE))
    return FALSE;
  if ( (oper & (OP_ERASE_FILE | OP_EXTRACT_FILE))
       && (oper & ~ (OP_ERASE_FILE | OP_EXTRACT_FILE)))
    return FALSE;
  if ( (oper & OP_HEX_DUMP) && (oper & ~OP_HEX_DUMP))
    return FALSE;
  if ( (oper & OP_ASCII_DUMP) && (oper & ~OP_ASCII_DUMP))
    return FALSE;

  if (waitFile == TRUE && (oper & OP_CATALOGUE))
    strcpy (fileMask, "*.*");

  if ( (oper & OP_FORMAT) && ! (oper & ~OP_FORMAT))
    oper |= OP_CREATE;

  return TRUE;
}
//-----------------------------------------------------------------------------
// Error reporting.
//-----------------------------------------------------------------------------
void PrintError (int err) {
  retVal = err;

  switch (err) {
  case NO_ERR :
    printf ("All done. End of session...");
    break;

  case ERR_CONF_FILE_MISSING :
    printf ("Config file '%s.ini' missing", exeName);
    break;

  case ERR_CREATE_IMAGE :
    printf ("Image '%s' already exist", imageName);
    break;

  case ERR_OPEN_IMAGE :
    printf ("Can't open image '%s'", imageName);
    break;

  case ERR_IMAGE_SIZE :
    printf ("Image '%s' has bad size", imageName);
    break;

  case ERR_READ_IMAGE :
    printf ("Error on read from the image '%s'", imageName);
    break;

  case ERR_WRITE_IMAGE :
    printf ("Error on write to the image '%s'", imageName);
    break;

  case ERR_IMG_EXT_MISSING :
    printf ("Extension of the Image name '%s' missing", imageName);
    break;

  case ERR_IMG_DEF_MISSING :
    printf ("Definition for Image type '%s' missing", imageExt);
    break;

  case ERR_IMG_DEF_ERROR :
    printf ("Error in definition for Image type '%s'", imageExt);
    break;

  case ERR_IMG_SYS_TOO_LONG :
    printf ("System file '%s' is too long. Max. length is %d bytes", fileName, systemSize);
    break;

  case ERR_IMG_NO_SYS :
    printf ("Image '%s' does not contain system track", imageName);
    break;

  case ERR_IMG_BAD_TYPE :
    printf ("Image '%s' is of different type as main image '%s'", fileName, imageName);
    break;

  case ERR_CREATE_FILE :
    printf ("File '%s' already exist", fileName);
    break;

  case ERR_OPEN_FILE :
    printf ("Can't open file '%s'", fileName);
    break;

  case ERR_READ_FILE :
    printf ("Error on read from the file '%s'", fileName);
    break;

  case ERR_WRITE_FILE :
    printf ("Error on write to the file '%s'", fileName);
    break;

  case ERR_DISK_FULL :
    printf ("Disk full");
    break;

  case ERR_DIRECTORY_FULL :
    printf ("Directory full");
    break;

  case ERR_FILE_EXIST :
    printf ("File '%s' already exist", fileName);
    break;

  case ERR_FILE_NOT_EXIST :
    printf ("File '%s' not found", fileName);
    break;

  case ERR_BAD_FILE_NAME :
    printf ("Name of this file '%s' has incorrect format", fileName);
    break;

  case ERR_DIR_ENTRY :
    printf ("Corrupted directory entry '%s'", fna.fn);
    break;

  case ERR_FILE_TOO_LONG :
    printf ("File '%s' is too long (%ld bytes). Max length is 8MB.", fileName, (long int) fileLength);
    break;
  }

  if (err != NO_ERR)
    printf (" !!!");
  printf ("\n");
}
//-----------------------------------------------------------------------------
// Short help.
//-----------------------------------------------------------------------------
void Usage (void) {
  const char *cpmName = "'cpm_name'";
  const char *cpmNameWithPath = "'[path/]cpm_name'";

  printf ("\nUsage:\n");
  printf ("  %s imagefile.ext [ -u usr ] -c [ %s ]\n", exeName, cpmName);
  printf ("  %s imagefile.ext [ -f | -q ] [ -u usr ] [ -a %s ]\n", exeName, cpmNameWithPath);
  printf ("  %s imagefile.ext [ -u usr ] -e %s\n", exeName, cpmName);
  printf ("  %s imagefile.ext [ -u usr ] -x %s\n", exeName, cpmNameWithPath);
  printf ("  %s imagefile.ext [ -u usr ] -h %s\n", exeName, cpmName);
  printf ("  %s imagefile.ext [ -u usr ] -t %s\n", exeName, cpmName);
  printf ("  %s imagefile.ext -w [path/]in_system_file\n", exeName);
  printf ("  %s imagefile.ext -i [path/]imagefile2.ext\n", exeName);
  printf ("  %s imagefile.ext -s [path/]out_system_file\n", exeName);
  printf ("    -c\tshow catalogue of the image\n");
  printf ("    -f\tfull format of the image (image will be created if not exist)\n");
  printf ("    -q\tquick format of the image (image will be created if not exist)\n");
  printf ("    -a\tadd file(s) to the image (image will be created if not exist)\n");
  printf ("    -e\terase file(s) from the image\n");
  printf ("    -x\textract file(s) from the image\n");
  printf ("    -h\tdisplay hex dump of the file\n");
  printf ("    -t\tdisplay content of the ASCII file\n");
  printf ("    -w\twrite system to the image from file\n");
  printf ("    -i\twrite system to the image from another image of the same type\n");
  printf ("    -s\textract system from the image and save to file\n");
  printf ("    -u\tdetermines user number 0 to 15\n");
  printf ("\tif not specified, files of all users are processed\n");
  printf ("\tand for switch -a user 0 is always used\n");
  printf ("    'imagefile.ext', 'imagefile2.ext' are image file names with extension\n");
  printf ("    'cpm_name' is the file name in CP/M 8.3 format\n");
  printf ("\t       which can contain wildcards '*' or '?'\n");
  printf ("\t       and can be with dir-path of the file(s) to add or extract.\n");

  printf ("\t       NOTICE: 'cpm_name' with wildcards must be enclosed\n");
  printf ("\t       in apostrophes to avoid wildcard filename expansion\n");
  printf ("\t       by your filesystem.\n");

  printf ("    'system_file' is binary file with system itself\n");
}
//---------------------------------------------------------------------------

