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
enum ERRORS_ENUM {
  ERR_OK               =  0,
  ERR_PRINT_USAGE      = -1,
  ERR_PRINT_VERSION    = -2,
  ERR_BAD_OPTIONS      = -3,
  ERR_OPEN_SRC_FILE    = -4,
  ERR_ACCESS_SRC_FILE  = -5,
  ERR_LENGTH_SRC_FILE  = -6,
  ERR_BAD_LEN_SRC_FILE = -7,
  ERR_READ_SRC_FILE    = -8,
  ERR_OPEN_DEST_FILE   = -9,
  ERR_ACCESS_DEST_FILE = -10,
  ERR_WRITE_DEST_FILE  = -11,
  ERR_NO_INPUT_FILE    = -12,
  ERR_INPUT_FILE_MORE  = -13,
  ERR_OUTPUT_FILE_MORE = -14,
  ERR_BAD_ADDRESS      = -15,
  ERR_BAD_FILE_NUMBER  = -16,
  ERR_BAD_FILE_TYPE    = -17,
  ERR_BAD_FILE_NAME    = -18
};
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
//---------------------------------------------------------------------------
  
  int parseBasicProgram (BYTE * out, FILE * in);

#ifdef __cplusplus
};
#endif // __cplusplus
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------


