/*
 * 
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
