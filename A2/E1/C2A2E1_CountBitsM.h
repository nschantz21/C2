/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-08
 * C2A2E1_CountBitsM.h
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define macro to determine the nober of bits of storage used for the data of an
 * object on any machine on which it runs.
 */
#ifndef C2A2E1_COUNTBITSM_H
#define C2A2E1_COUNTBITSM_H

#include <limits.h>

/* sizeof needs to be cast to int */
#define CountBitsM(objectOrType) (CHAR_BIT * (int)sizeof(objectOrType))

#endif
