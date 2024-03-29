/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-15
 * C2A3E4_OpenFile.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 *
 * Program to open file in read-only text mode
 */

#include <stdlib.h>
#include <stdio.h>

FILE *OpenFile(const char *filename)
{
    /* open file in read-only text mode */
    FILE *input_file;
    input_file = fopen(filename, "r");
    /* file open check */
    if (input_file == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    else {
        return input_file;
    }
}
