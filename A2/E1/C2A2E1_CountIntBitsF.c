/*
 * 
 * Determine the number of bits used to represent a type int value on any
 * machine on which the program is run.
 * 
 * Could the value produced by CountBitsM for type int be different than the value produced by
 * CountIntBitsF? Why or why not?
 * 
 */

int CountIntBitsF(void)
{
    return (int)sizeof(int);
}
