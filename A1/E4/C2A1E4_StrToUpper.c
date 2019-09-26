#include <stdlib.h>
#include <ctype.h>

size_t StrToUpper(char *s1, const char *s2) {
    /* create reference to beginnning of source string */
    const char * const START = s2;
    
    /* copy and convert source to target */
    while (*s2) {
        *s1++ = toupper(*s2++);
    }
    
    /* add null pointer to end of the target string */
    *s1 = '\0';
    
    return (size_t)(s2 - START);
}