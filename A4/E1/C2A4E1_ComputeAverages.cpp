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
    for (int d1c = 0; d1c < DIM1; d1c++){
        /* DIM1 */
        for (int d2c = 0; d2c < DIM2; d2c++){
            /* DIM2 */
            for (int d3c = 0; d3c < DIM3; d3c++){
                /* DIM3 */
                for (int d4c = 0; d4c < DIM4; d4c++){
                    /* DIM4 */
                    runnestAvg += inputArray[d1c][d2c][d3c][d4c];
                }
            }   
        }
    }
    *nestAvg = runnestAvg / TOTAL;
	
	/* average using linear access */
	float *pnt, linsum = 0;
	for (pnt = (float *)inputArray; pnt < (float *)inputArray + DIM1 * DIM2 * DIM3 * DIM4; ++pnt) {
        linsum += *pnt;
	}
	*linAvg = linsum / TOTAL;

    return;
}
