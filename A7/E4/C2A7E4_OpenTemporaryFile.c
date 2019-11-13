/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-12
 * C2A7E4_OpenTemporaryFile.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Open a temporary file using standard library tmpfile function.
 */
#include <stdlib.h>
#include <stdio.h>

FILE *OpenTemporaryFile(void)
{
    printf("Opening Temp File");
    /* open file in read-only text mode */
    FILE *tmp = tmpfile();
    /* file open check */
    if (tmp == NULL) {
        fprintf(stderr, "Can't open tmpfile\n");
        exit(EXIT_FAILURE);
    }
    else {
        return tmp;
    }
}
