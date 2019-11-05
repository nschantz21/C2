/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-05
 * C2A6E2_SortValues.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Sort given array in descending order using "bubble sort algorithm". Return
 * pointer to first element of sorted array.
 */
#include <cstdlib>

float *SortValues(float *first, size_t elements)
{
    float  *last = &first[elements - 1];
    bool didSwap;
    do {
        float *current;
        /* loop through array swapping positions of elements larger than those preceeding */
        for (didSwap = false, current = first; current < last; ++current) {
            if (current[0] < current[1]) {
                float temp = current[0];
                current[0] = current[1];
                current[1] = temp;
                didSwap = true;
            }
        }
        /* decrement last so we don't check the bubbled value */
        --last;
    /* algorithm done is no swap */
    } while (didSwap);

    return first;
}
