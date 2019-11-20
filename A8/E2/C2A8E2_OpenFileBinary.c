/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-19
 * C2A8E2_OpenFileBinary.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Opens the file named in fileName in the read-only binary mode. If the open
 * fails an error message is output to stderr and the program is terminated with
 * an error exit code. The error message mentions the name of the failing file.
 */
#include <stdlib.h>
#include <stdio.h>

FILE *OpenFileBinary(const char *fileName)
{
    /* open file in read-only binary mode */
    FILE *input_file;
    input_file = fopen(fileName, "rb");
    /* file open check */
    if (input_file == NULL) {
        fprintf(stderr, "Can't open %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    else {
        return input_file;
    }
}
