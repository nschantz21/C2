#include <string.h>
#include <stdlib.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize) {
    if (newSize == 0) {
        return NULL;
    } else {
        // Dynamically allocate a new block containing newSize uninitialized bytes.
        int *newBlock;
        newBlock = (int *)malloc(newSize);
        if (newBlock == NULL) {
            return NULL;
        } else if (pOld == NULL) {
            return newBlock; /* return pointer to newBlock */
        } else {
            if (newSize > oldSize) {
                // copy oldSize bytes from pOld to the new block.
                memcpy(newBlock, pOld, oldSize);
            } else {
                // copy newSize bytes from pOld to the new block.
                memcpy(newBlock, pOld, newSize);
            }
            free(pOld);
            return newBlock;
        }
        
    }

    
    
}
