/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E1_Macros.h
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define Product, Negate, and Elements macros to be used in main-Driver
 * instructor file.
 */


#ifndef C2A1E1_MACROS_H
#define C2A1E1_MACROS_H

/* Return product of any two arguments of any arithmetic tipe passed to it. */
#define Product(ARTH1, ARTH2) ((ARTH1) * (ARTH2))

/* Return negated value of any arithmetic argument of any tupe passed to it. */
#define Negate(NUM) (-(NUM))

/* 
 * Return count of the number of elements in any 1-d array or any type whose
 * array designator is passed to it 
 */
#define Elements(COLL) (sizeof(COLL)/sizeof((COLL)[0]))

#endif
