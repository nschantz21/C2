/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-22
 * C2A4E1_RandomizeArray.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Seed the random number generator with the value of the real time clock (RTC) 
 * using the standard library srand and time functions. Then, initialize each element
 * of the 4D array represented by the function's parameter with the unaltered
 * values returned from repeated calls to the library rand function 
 */
#include <stdlib.h>
#include <time.h>
#include "C2A4E1_ArraySize.h"
#include <iostream>
using namespace std;

void RandomizeArray(float inputArray[][DIM1][DIM2][DIM3][DIM4])
{
    /* seed random number generator with value of RTC */
    srand(time(NULL));
    
    /* initialize each element of 4D array */
    /* DIM1 */
    for (int d1c = 0; d1c < DIM1; d1c++){
        /* DIM2 */
        for (int d2c = 0; d2c < DIM2; d2c++){
            /* DIM3 */
            for (int d3c = 0; d3c < DIM3; d3c++){
                /* DIM4 */
                for (int d4c = 0; d4c < DIM4; d4c++){
                    (*inputArray)[d1c][d2c][d3c][d4c] = rand();
                    cout << (*inputArray)[d1c][d2c][d3c][d4c];
                }
            }   
        }
    }
}
