/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-29
 * C2A5E1_Create2D.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Function to create a 2-dimensional pointer array of data type Type having the number of
 * rows and columns specified by  rows and cols
 */
#include <stdlib.h>
#include <stdio.h>
#include "C2A5E2_Type-Driver.h"


void *SafeMalloc(size_t size)
{
    void *vp;
    if ((vp = malloc(size)) == NULL) {
        fputs("Out of Memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

Type **Create2D(size_t rows, size_t cols)
{
    Type *mem = (Type *)malloc(rows * cols * sizeof(Type));
    Type **p = (Type **)malloc(rows * sizeof(Type *));
    p[0] = mem;
    for(int i = 1; i < rows; i++)
        p[i] = p[i-1] + cols;
    return (p);
}

void Free2D(void *p)
{
    free(p);
}
