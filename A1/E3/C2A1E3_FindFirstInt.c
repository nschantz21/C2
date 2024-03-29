/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E3_FindFirstInt.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * FindFirstInt must find the first occurrence of the value represented by value
 * in the array represented ptr , which has count elements. If the value is found
 * a pointer to that element is returned. Otherwise, a null pointer is returned.
 */

#include <stddef.h>
#include <stdio.h>

int *FindFirstInt(const int *ptr, size_t count, int value) 
{
    /* iterate through array and return first element equal to value */
    for (size_t counter = 0; counter < count; counter++) {
        if (ptr[counter] == value) {
            /* required to cast ptr to int pointer from const int pointer */
            return (int *)&ptr[counter];
        }
    }
    /* return null pointer if value not found in array */
    return NULL;
}
