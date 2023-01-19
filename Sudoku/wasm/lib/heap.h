#ifndef _HEAP_H
#define _HEAP_H
#define EXPORT(name) __attribute__((used, export_name(#name))) name
// "imports" odpovídá importObject.imports v JS, default je to importObject.env
#define IMPORT(name) __attribute__((import_module("imports"),import_name(#name))) name
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
void * EXPORT(malloc) (unsigned long n);
void   EXPORT(free)   (void * p);

extern char * _HEAP_MAX;
#ifdef __cplusplus
};
#endif //__cplusplus
#endif // _HEAP_H
