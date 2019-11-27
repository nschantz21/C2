/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-19
 * C2A8E2_DisplayModifiedSingleReals.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Displays an aligned table in which each 32-bit pattern is represented by an 8
 * character hexadecimal value (letters may be uppercase or lowercase) followed
 * by what that value represents if interpreted as a "Modified Single Real". That
 * representation will always be preceded by a plus sign or a minus sign as
 * appropriate.
 */
#include <stdio.h>
#include <limits.h>
#include <math.h>

#define F_NORM    1
#define F_DENORM  2
#define F_PZERO   3
#define F_NZERO   (-F_PZERO)
#define F_PINF    4
#define F_NINF    (-F_PINF)
#define F_PNAN    5
#define F_NNAN    (-F_PNAN)

#define SIGN_MASK 0x80000000uL
#define EXP_MASK  0x7FC00000uL
#define FRAC_MASK 0x3FFFFFuL
#define FRAC_BITS 22
#define EXP_NBIAS 255
#define EXP_DBIAS 254
#define EXP_MAX   511
#define BUFFLEN   4
#define READB     1
#define THEPOWER  2.0

/* helper function */
static int EvalSingleReal(unsigned long pattern, double *result)
{
    /* get parts of unsigned long */
    int signIsNegative = !!(SIGN_MASK & pattern);
    int exponent = (EXP_MASK & pattern) >> FRAC_BITS;
    long fraction = FRAC_MASK & pattern;
    int status;
    /* determine type based on parts of pattern */
    if (exponent == 0 && fraction == 0) {
        /* Zero */
        status = signIsNegative ? F_NZERO : F_PZERO;
        *result = 0;
    } else if (exponent == EXP_MAX && fraction == 0) {
        /* infinity */
        status = signIsNegative ? F_NINF : F_PINF;
    } else if (exponent == EXP_MAX && fraction != 0) {
        /* NaN */
        status = signIsNegative ? F_NNAN : F_PNAN;
    } else {
        /* normal and denormal */
        *result = fraction * pow(THEPOWER, -FRAC_BITS);
        int bias;
        if (exponent != 0) {
            /* normal */
            bias = EXP_NBIAS;
            status = F_NORM;
            ++*result;
        } else {
            /* denormal */
            bias = EXP_DBIAS;
            status = F_DENORM;
        }
        *result *= pow(THEPOWER, exponent - bias);
        if (signIsNegative)
            *result = -*result;
    }
    return(status);
}

void DisplayModifiedSingleReals(FILE *inFile)
{
    /* Read each 4-byte group from the input file into a 4-element unsigned char array */
    int counter1 = 0;
    unsigned char buff[BUFFLEN];
    /* read bytes into char array elements and check for end of file */
    while ((fread(&buff[counter1], sizeof(unsigned char), READB, inFile)) == READB) {        
        counter1++;
        if (counter1 == BUFFLEN) {
            /* convert array of bytes to unsigned long */
            unsigned long temp = 0;
            for (int bufbit = BUFFLEN - 1; bufbit >= 0; bufbit--) {
                temp |= buff[bufbit] << (CHAR_BIT * (BUFFLEN - 1 - bufbit));
            }
            /* call function to convert unsigned long to double */
            double result;
            int status = EvalSingleReal(temp, &result);
            printf("0x%08x ", (unsigned int)temp);
            /* check for negativity */
            int signIsNegative = !!(SIGN_MASK & temp);
            /* print result based on status */
            switch (status) {
                case 1:
                    /* normal */
                    if (!signIsNegative) {
                        printf("+");
                    }
                    printf("%e Normal\n", result);
                    break;
                case 2:
                    /* denormal */
                    if (!signIsNegative) {
                        printf("+");
                    }
                    printf("%e Denormal\n", result);
                    break;                
                /* zero */
                case 3:                
                    printf("+%e Zero\n", result);
                    break;                
                case -3:
                    printf("-%e Zero\n", result);             
                    break;                
                /* infinity */
                case 4:
                    printf("+INF\n");
                    break;                
                case -4:
                    printf("-INF\n");
                    break;
                /* NaN */
                case 5:
                    printf("+NAN\n");
                    break;                
                case -5:
                    printf("-NAN\n");
                    break;
            }
            counter1 = 0;
        }
    }
    /* check for unexpected EOF */
    if (counter1 != 0) {
        printf("Unexpected EOF\n");
    }
}
