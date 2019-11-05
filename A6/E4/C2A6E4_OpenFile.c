/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-05
 * C2A6E4_OpenFile.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 *
 * Program to open file in read-only text mode
 */

#include <stdlib.h>
#include <stdio.h>

FILE *OpenFile(const char *fileName)
{
    /* open file in read-only text mode */
    FILE *input_file;
    input_file = fopen(fileName, "r");
    /* file open check */
    if (input_file == NULL) {
        fprintf(stderr, "Can't open %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    else {
        return input_file;
    }
}
