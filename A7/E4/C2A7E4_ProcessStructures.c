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
 * Were the results you got correct for your implementation?
 * How many padding bytes were in your structure?
 */
#include <stdio.h>
#include <stdlib.h>
#include "C2A7E4_Test-Driver.h"

void *ReverseEndian(void *ptr, size_t size);

struct Test *ReverseMembersEndian(struct Test *ptr)
{
    ptr->flt = *(float *)ReverseEndian((void *)&(ptr->flt), sizeof(ptr->flt));
    ptr->dbl = *(double *)ReverseEndian((void *)&(ptr->dbl), sizeof(ptr->dbl));
    ptr->vp = ReverseEndian(ptr->vp, sizeof(ptr->vp));
    return ptr;
}

struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
    if (fread(&ptr, sizeof(*ptr), count, fp) != count) {
        fprintf(stderr, "Reading Error\n");
        exit(EXIT_FAILURE);  
    } else {
        return ptr;        
    }
}

struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
    if (fwrite(&ptr, sizeof(*ptr), count, fp) != count) {
        fprintf(stderr, "Writing Error\n");
        exit(EXIT_FAILURE);    
    } else {
        return (struct Test *)ptr;
    }

}
