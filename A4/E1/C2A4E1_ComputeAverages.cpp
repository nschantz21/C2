/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-22
 * C2A4E1_ComputeAverages.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * computes the average of all elements in the 4D array. store result in address
 * passed to function.
 */
#include "C2A4E1_ArraySize.h"

void ComputeAverages(float inputArray[][DIM2][DIM3][DIM4], float *nestAvg, float *linAvg)
{
    /* array average using nested for loop access */
    float runnestAvg = 0;
    for (int index1 = 0; index1 < DIM1; index1++) {
        /* DIM1 */
        for (int index2 = 0; index2 < DIM2; index2++) {
            /* DIM2 */
            for (int index3 = 0; index3 < DIM3; index3++) {
                /* DIM3 */
                for (int index4 = 0; index4 < DIM4; index4++) {
                    /* DIM4 */
                    runnestAvg += inputArray[index1][index2][index3][index4];
                }
            }
        }
    }
    *nestAvg = runnestAvg / TOTAL;
    
    /* average using linear access */
    float linsum = 0;
    for (float *pnt = (float *)inputArray; pnt < (float *)inputArray + DIM1 * DIM2 * DIM3 * DIM4; ++pnt) {
        linsum += *pnt;
    }
    *linAvg = linsum / TOTAL;

    return;
}
