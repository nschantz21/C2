/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-29
 * C2A5E1_SwapObjects.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Make function to swap memory addresses of two objects based on pointers and size
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapObjects(void *pa, void *pb, size_t size)
{
    /* initialize holder pointer */
    void *p;
    if ((p = malloc(size)) == NULL) {
        // error message and termination
        fputs("unable to allocate memory", stderr);
        exit(EXIT_FAILURE);
    }
    
    /* swap memory using holder pointer p */
    memcpy(p, pa, size);
    memcpy(pa, pb, size);
    memcpy(pb, p, size);
    free(p);
    return;
}
