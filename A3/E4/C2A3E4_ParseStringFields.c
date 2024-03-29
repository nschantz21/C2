/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-15
 * C2A3E4_ParseStringFields.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Reads input from the text file in fp one line at a time and uses the strtok
 * function to find each delimited field and display it on a separate output line
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define DELIMS "AEIOUaeiou\t\n"
#define CHARBUFF 255

void ParseStringFields(FILE *fp)
{
    char store_str[CHARBUFF];
    /* read until end of file */
    while (!feof(fp)) {
        /* read input from file one line at a time. parse on newline */
        fgets(store_str, CHARBUFF, fp);
        /* tokenize line from file */
        char *pch = strtok(store_str, DELIMS);
        while (pch != NULL) {
            /* remove leading whitespace defined by isspace */
            while (isspace(pch[0])) {
                /* reassign pointer to next element if isspace */
                pch = &pch[1];
            }
            printf("%s\n", pch);
            pch = strtok(NULL, DELIMS);
        }
    }
    return;
}
