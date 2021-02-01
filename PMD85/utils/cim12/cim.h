//-----------------------------------------------------------------------------
#ifndef _MAIN_H_
#define _MAIN_H_
//-----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include <stdint.h>
typedef uint8_t  BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

typedef int     BOOL;
#define FALSE   0
#define TRUE    (!FALSE)
//-----------------------------------------------------------------------------

// file control block
struct _FCB {
  char un;      // user number (0 to 15, 229 for empty directory entry)
  char fn[8];   // file name
  char ft[3];   // file type (ft[0].7 = Read Only, ft[1].7 = Hidden)
  BYTE ex;      // extent (0 to 31)
  BYTE s1;      // system reserved (always 0)
  BYTE s2;      // high order bits of extent (only lower 7 bits)
  BYTE rc;      // record count for extent ex (0 to 128)
  BYTE au[16];  // allocation unit numbers that are occupied by file
}__attribute__((packed));
typedef struct _FCB FCB;

typedef struct {
  char user;
  char fn[13];
  int totrc;
  int size;
  BOOL rdonly;
  BOOL hidden;
} FILE_NAME_ATTR;

//-----------------------------------------------------------------------------
#define XVERSION                0x12
#define XNAME                   "CP/M Image Manager utility"
#define XAUTHOR                 "RM-TEAM, 1/2012"

#define BUFFER_SIZE             16384

#define FILL_BYTE               -27    // 0xE5 229
#define RECORD_SIZE             128
#define DIR_ENTRY_SIZE          32
#define EXTENT_SIZE             16384
#define RECORDS_PER_EXTENT      (EXTENT_SIZE / RECORD_SIZE)
#define DIR_ENTRIES_PER_RECORD  (RECORD_SIZE / DIR_ENTRY_SIZE)

#define MAX_CPM_FILE_SIZE       (8*1024*1024)       // 8MB
#define MAX_CPM_DISK_SIZE       (1024*1024*1024)    // 1GB

//-----------------------------------------------------------------------------
#define MAX_PATH_LEN            260
#define MAX_FILE_LEN            256
#define MAX_EXT_LEN             256

//-----------------------------------------------------------------------------
#define NO_ERR                   0
#define ERR_CREATE_IMAGE        -1
#define ERR_OPEN_IMAGE          -2
#define ERR_IMAGE_SIZE          -3
#define ERR_READ_IMAGE          -4
#define ERR_WRITE_IMAGE         -5

#define ERR_CREATE_FILE         -6
#define ERR_OPEN_FILE           -7
#define ERR_READ_FILE           -8
#define ERR_WRITE_FILE          -9

#define ERR_DISK_FULL           -10
#define ERR_DIRECTORY_FULL      -11
#define ERR_FILE_EXIST          -12
#define ERR_FILE_NOT_EXIST      -13
#define ERR_BAD_FILE_NAME       -14
#define ERR_DIR_ENTRY           -15

#define ERR_IMG_EXT_MISSING     -16
#define ERR_CONF_FILE_MISSING   -17
#define ERR_IMG_DEF_MISSING     -18
#define ERR_IMG_DEF_ERROR       -19

#define ERR_IMG_SYS_TOO_LONG    -20
#define ERR_IMG_NO_SYS          -21
#define ERR_IMG_BAD_TYPE        -22

#define ERR_FILE_TOO_LONG       -23

#define ERR_FATAL_ERROR         -99

//-----------------------------------------------------------------------------
#define OP_CREATE                1
#define OP_FORMAT                2
#define OP_QUICK                 4
#define OP_ADD_FILE              8
#define OP_ERASE_FILE           16
#define OP_EXTRACT_FILE         32
#define OP_CATALOGUE            64
#define OP_HEX_DUMP            128
#define OP_ASCII_DUMP          256
#define OP_WRITE_SYS           512
#define OP_COPY_SYS           1024
#define OP_EXTRACT_SYS        2048

//-----------------------------------------------------------------------------
#define PAR_SPT                  1
#define PAR_XLT                  2
#define PAR_BLS                  4
#define PAR_EXM                  8
#define PAR_DSM                 16
#define PAR_DRM                 32
#define PAR_OFF                 64
#define PAR_OFFX               128
#define PAR_ALL                  (PAR_SPT | PAR_XLT | PAR_BLS | PAR_EXM | PAR_DSM | PAR_DRM | PAR_OFF)

//-----------------------------------------------------------------------------
void PrepareNameAttr(int de);
BOOL CheckFileName(char *mask, const char *fn);
BOOL MarkAU(int auNum, BOOL state);
int FindFirstFreeAU(void);
int GetFreeAuCount(void);
int FindFreeDirEntry(void);
int FindDirEntry(char *ent, int from);
int CalcFileRecs(char *ent);
int CpmFindFirstFile(char *cpmMask);
int CpmFindNextFile(void);
BOOL ComputeTrackSector(int au, int rec, int *t, int *s);

void AddFiles(void);
void EraseFiles(void);
void ExtractFiles(void);
void Catalogue(void);
void AsciiDump(void);
void HexDump(void);
void WriteSys(void);
void CopySys(void);
void ExtractSys(void);

BOOL ReadDirectory(void);
BOOL WriteDirectory(void);

BOOL OpenCurrentFile(BOOL create);
void CloseCurrentFile(void);

BOOL OpenImage(BOOL create);
void CloseImage(void);
BOOL WriteBoot(BOOL writeTail);
BOOL ReadSector(BYTE *buf, int track, int sector);
BOOL WriteSector(BYTE *buf, int track, int sector);
BOOL CleanDirectory(void);

char* trimLeft(char *in_out);
char* trimRight(char *in_out);
char* trim(char *in_out);
int parseNumber(char *s);

int ReadConfig(char *imgName);
void ExtractPathName(char *path, char *name, char *ext, const char *src);
BOOL PrepareParams(int argc, char* argv[]);

void PrintError(int err);
void Usage(void);

#ifdef __cplusplus
};
#endif //__cplusplus

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

 