/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-22
 * C2A4E2_StorageMap5D.h
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define macro to access any element of an arbitrarily sized array given a
 * pointer to the array, the element index, and array dimensions
 */
#ifndef C2A4E2_STORAGEMAP5D_H
#define C2A4E2_STORAGEMAP5D_H

#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4)\
    (*((ptr)\
    + (idx0)*(dim1) * (dim2) * (dim3) * (dim4)\
    + (idx1) * (dim2) * (dim3) * (dim4)\
    + (idx2) * (dim3) * (dim4)\
    + (idx3) * (dim4)\
    + (idx4)))

#endif
