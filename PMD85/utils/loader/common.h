//---------------------------------------------------------------------------
#ifndef commonH
#define commonH
//---------------------------------------------------------------------------
typedef unsigned char       BYTE;
typedef unsigned short int  WORD;
typedef int                 BOOL;
#define FALSE                 0
#define TRUE                  !FALSE

//---------------------------------------------------------------------------
#define ERR_OK                0
#define ERR_PRINT_USAGE       -1
#define ERR_PRINT_VERSION     -2
#define ERR_BAD_OPTIONS       -3
#define ERR_OPEN_SRC_FILE     -4
#define ERR_ACCESS_SRC_FILE   -5
#define ERR_LENGTH_SRC_FILE   -6
#define ERR_BAD_LEN_SRC_FILE  -7
#define ERR_READ_SRC_FILE     -8
#define ERR_OPEN_DEST_FILE    -9
#define ERR_ACCESS_DEST_FILE  -10
#define ERR_WRITE_DEST_FILE   -11
#define ERR_NO_INPUT_FILE     -12
#define ERR_INPUT_FILE_MORE   -13
#define ERR_OUTPUT_FILE_MORE  -14
#define ERR_BAD_ADDRESS       -15
#define ERR_BAD_FILE_NUMBER   -16
#define ERR_BAD_FILE_TYPE     -17
#define ERR_BAD_FILE_NAME     -18

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
//---------------------------------------------------------------------------
// pmdtape.c
  int parseBasicProgram (BYTE * out, FILE * in);

#ifdef __cplusplus
};
#endif // __cplusplus
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------


