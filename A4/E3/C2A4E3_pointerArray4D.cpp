/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-22
 * C2A4E3_pointerArray4D.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * make 4D array using pointer arrays
 */

/* define array dimensions */
extern const int DIM0 = 2, DIM1 = 3, DIM2 = 4, DIM3 = 5;

/* declare highest dimension array */
float v0[DIM3], v1[DIM3], v2[DIM3], v3[DIM3], v4[DIM3], v5[DIM3], v6[DIM3],
    v7[DIM3], v8[DIM3], v9[DIM3], v10[DIM3], v11[DIM3], v12[DIM3], v13[DIM3],
    v14[DIM3], v15[DIM3], v16[DIM3], v17[DIM3], v18[DIM3], v19[DIM3], v20[DIM3],
    v21[DIM3], v22[DIM3], v23[DIM3];
/* pointer to array of arrays */
float *y0[DIM2] = {v0, v1, v2, v3}, *y1[DIM2] = {v4, v5, v6, v7},
    *y2[DIM2] = {v8, v9, v10, v11}, *y3[DIM2] = {v12, v13, v14, v15},
    *y4[DIM2] = {v16, v17, v18, v19}, *y5[DIM2] = {v20, v21, v22, v23};
/* pointer to array of pointers */
float **x0[DIM1] = {y0, y1, y2}, **x1[DIM1] = {y3, y4, y5};
/* pointer to array of pointers to arrays of pointers */
float ***pointerArray4D[DIM0] = {x0, x1};
