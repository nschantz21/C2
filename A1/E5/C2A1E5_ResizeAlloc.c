/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E5_ResizeAlloc.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * ResizeAlloc either dynamically allocates an entirely new block of memory 
 * containing newSize bytes or, in effect, resizes an existing block in pOld
 * containing oldSize bytes to contain newSize bytes. When resizing occurs all
 * existing data that will fit into newSize bytes will be preserved.
 */

#include <string.h>
#include <stdlib.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize)
{
    if (newSize == 0) {
        return NULL;
    } else {
        /* Dynamically allocate a new block containing newSize uninitialized bytes. */
        int *newBlock;
        newBlock = (int *)malloc(newSize);
        
        /* if you can't allocate the memory return null pointer */
        if (newBlock == NULL) {
            return NULL;
        } else if (pOld == NULL) {
            /* if the old pointer is null return pointer to newBlock */
            return newBlock;
        } else {
            if (newSize > oldSize) {
                /* copy oldSize bytes from pOld to the new block. */
                memcpy(newBlock, pOld, oldSize);
            } else {
                /* copy newSize bytes from pOld to the new block. */
                memcpy(newBlock, pOld, newSize);
            }
            free(pOld);
            return newBlock;
        }   
    }
}
