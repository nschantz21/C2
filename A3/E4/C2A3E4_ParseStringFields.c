/*
 * 
 */

#include <stdio.h>
#include <string.h>

#define DELIMS "AEIOUaeiou\t\n"
#define CHARBUFF 255

void ParseStringFields(FILE *fp)
{
    char store_str[CHARBUFF];
    while (!feof(fp)) {
        /* read input from file one line at a time */
        fgets(store_str, CHARBUFF, fp);
        /* check each char against each delimiter */
        for (int ccount = 0; ccount < strlen(store_str); ccount++) {
            /* find each delim field and display on seperate output line */
            for (int dcount = 0; dcount < strlen(DELIMS); dcount++) {
                char this_delim = DELIMS[dcount];
                
                }
            }
        }
    return;
}
