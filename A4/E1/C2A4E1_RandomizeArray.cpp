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
#include <cstdlib>
#include <ctime>
#include "C2A4E1_ArraySize.h"

void RandomizeArray(float inputArray[][DIM2][DIM3][DIM4])
{
    /* seed random number generator with value of RTC */
    srand((unsigned int)time(NULL)); 
    /* DIM1 */
    for (int da = 0; da < DIM1; da++){
        /* DIM2 */
        for (int db = 0; db < DIM2; db++){
            /* DIM3 */
            for (int dc = 0; dc < DIM3; dc++){
                /* DIM4 */
                for (int dd = 0; dd < DIM4; dd++){
                    inputArray[da][db][dc][dd] = (float)rand();
                }
            }   
        }
    }
}
