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
#include <stdio.h>

int IsLittleEndian(void)
{
    const int word = 1;
    return (int)*(char *)&word;
}

/*
 * ptr –  a pointer to a scalar object whose endianness is to be reversed
 * size – the number of bytes in the object
 */
void *ReverseEndian(void *ptr, size_t size)
{
    /* pointer to first byte */
    char *head = (char *)ptr;
    /* pointer to last byte */
    char *tail = head + size - 1;
    
    /* swap bytes at either end */
    for (; tail > head; --tail, ++head) {
        char temp = *head;
        *head = *tail;
        *tail = temp;
    }
    
    return ptr;
}
