/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-22
 * C2A4E1_WorkerFunction.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define WorkerFunction to call RandomizeArray and ComputeAverages given array
 * using dimensions from C2A4E1_ArraySize.h
 */

#include "C2A4E1_ArraySize.h"

void RandomizeArray(float inputArray[][DIM1][DIM2][DIM3][DIM4]);
void ComputeAverages(float inputArray[][DIM1][DIM2][DIM3][DIM4], float *nestedAvg, float *linearAvg);

void WorkerFunction(float *nestedAvg, float *linearAvg)
{
    float (*testArray)[DIM1][DIM2][DIM3][DIM4];
    RandomizeArray(testArray);
    ComputeAverages(testArray, nestedAvg, linearAvg);
    return;
}
