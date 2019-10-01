/*
 * 
 * Define macro to determine the nober of bits of storage used for the data of an
 * object on any machine on which it runs.
 */
#ifndef C2A2E1_COUNTBITSM_H
#define C2A2E1_COUNTBITSM_H

#include <limits.h>

#define CountBitsM(objectOrType) (int)(CHAR_BIT * sizeof(objectOrType))

#endif
