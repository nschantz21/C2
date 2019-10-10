/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-08
 * C2A2E1_CountIntBitsF.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Determine the number of bits used to represent a type int value on any
 * machine on which the program is run.
 * 
 * Could the value produced by CountBitsM for type int be different than the value produced by
 * CountIntBitsF? Why or why not?
 * Answer: Yes. The value produced by CountBitsM may include inactive bits in the
 * size, while CountIntBitsF should not
 */

int CountIntBitsF(void)
{
    unsigned int get_size = 1;
    int bit_count;
    for (bit_count = 0; get_size != 0; bit_count++)
    {
        /* shift and update get_size left 1 */
        get_size <<= 1;
    }
    return bit_count;
}
