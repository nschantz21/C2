/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E4_StrToUpper.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * StrToUpper copies the string represented by its second parameter into the
 * memory represented by its first parameter, with any lowercase characters
 * converted to uppercase. The length of the string, not including its null
 * terminator character, is returned.
 */

#include <stdlib.h>
#include <ctype.h>

size_t StrToUpper(char *s1, const char *s2)
{
    /* create reference to beginnning of source string */
    const char * const START = s2;
    
    /* copy and convert source to target */
    while (*s2) {
        *s1++ = (char)toupper(*s2++);
    }
    
    /* add null pointer to end of the target string */
    *s1 = '\0';
    return (size_t)(s2 - START);
}
