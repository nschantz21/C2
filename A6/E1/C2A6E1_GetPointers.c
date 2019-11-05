/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-05
 * C2A6E1_GetPointers.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define two functions. One to return a pointer to the stdlib printf function.
 * The other to return a pointer to the stdlib puts function.
 */
#include <stdio.h>

int (*GetPrintfPointer(void))(const char *format, ...)
{
    static int (*pPrintf)(const char *format, ...);
    pPrintf = printf;
    return pPrintf;
}

int (*GetPutsPointer(void))(const char *str)
{
    static int (*pPuts)(const char *str);
    pPuts = puts;
    return pPuts;
}
