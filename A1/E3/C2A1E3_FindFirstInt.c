#include <stddef.h>
#include <stdio.h>

int *FindFirstInt(const int *ptr, size_t count, int value) {
    
    size_t counter = 0;
    
    while (counter < count) {
        
        if (ptr[counter] == value) return (int *)&ptr[counter];
        
        counter++;
    }
    return NULL;
}
