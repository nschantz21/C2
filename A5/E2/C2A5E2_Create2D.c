/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-29
 * C2A5E2_Create2D.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Function to create a 2-dimensional pointer array of data type Type having the number of
 * rows and columns specified by  rows and cols
 */
#include <stdlib.h>
#include <stdio.h>
#include "C2A5E2_Type-Driver.h"


static void *SafeMalloc(size_t size)
{
    /* allocate memory and check for safety */
    void *vp;
    if ((vp = malloc(size)) == NULL) {
        fputs("Out of Memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

Type **Create2D(size_t rows, size_t cols)
{
    /* allocate memory all at once */
    Type **mem = (Type **)SafeMalloc(rows * cols * sizeof(Type) + rows * sizeof(Type *));
    /* get address of first subarray */
    Type *subarray = (Type *)&mem[rows];
    for (size_t subaddr = 0; subaddr < rows; ++subaddr) {
        /* set address of subarray in of first row number of elements */
        mem[subaddr] = subarray;
        /* calculate next subarray address */
        subarray += cols;
    }
    return(mem);
}

void Free2D(void *p)
{
    free(p);
}
