/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-12
 * C2A7E3_ReverseEndian.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Convert any scalar object pointed to by ptr from big endian to little endian
 * by swapping its bytes.
 */
#include <stddef.h>

void *ReverseEndian(void *ptr, size_t size)
{
    /* swap bytes at either end */
    for (char *head = (char *)ptr, *tail = head + size - 1; tail > head; --tail, ++head) {
        char temp = *head;
        *head = *tail;
        *tail = temp;
    }
    
    return ptr;
}
