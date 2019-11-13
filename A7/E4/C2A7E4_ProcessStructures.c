/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-12
 * C2A7E4_ProcessStructures.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Create fucntions ReverseMembersEndian, ReadStructures, and WriteStructures
 * 
 * Were the results you got correct for your implementation? yes
 * How many padding bytes were in your structure? 4
 */
#include <stdio.h>
#include <stdlib.h>
#include "C2A7E4_Test-Driver.h"

void *ReverseEndian(void *ptr, size_t size);

struct Test *ReverseMembersEndian(struct Test *ptr)
{
    /* Reverse endianess of each member of struct */
    ReverseEndian((void *)&ptr->flt, sizeof(ptr->flt));
    ReverseEndian((void *)&ptr->dbl, sizeof(ptr->dbl));
    ReverseEndian((void *)&ptr->vp, sizeof(ptr->vp));
    return ptr;
}

struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
    /* attempt to read structs from file */
    if (fread(ptr, sizeof(*ptr), count, fp) != count) {
        /* report if fails */
        fprintf(stderr, "Reading Error\n");
        exit(EXIT_FAILURE);
    } else {
        return ptr;        
    }
}

struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
    /* attempt to write structs to file */
    if (fwrite(ptr, sizeof(*ptr), count, fp) != count) {
        /* report if fails */
        fprintf(stderr, "Writing Error\n");
        exit(EXIT_FAILURE);    
    } else {
        return (struct Test *)ptr;
    }
}
