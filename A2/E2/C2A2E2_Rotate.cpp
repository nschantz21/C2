/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-08
 * C2A2E2_Rotate.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Program produces the value of parameterobject as if it had been rotated by the
 * number of positions and in the direction specified by count.
 */

int CountIntBitsF();

unsigned Rotate(unsigned object, int count)
{
    int mask = CountIntBitsF() - 1;
    /* rotate right if positive, left if negative */
    if (count > 0) {
        count &= mask;
        return (object >> count) | (object << (-count & mask));
    } else {
        count = (-count) & mask;
        return (object << count) | (object >> (-count & mask));
    }
}
