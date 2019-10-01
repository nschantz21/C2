/*
 * 
 */

extern int CountIntBitsF();

unsigned Rotate(unsigned object, int count)
{
    int int_bits = CountIntBitsF();
    if (count >= 0) {
        /* right rotate */
        return (object >> count)|(object << (int_bits - count));
    } else {
        /* left rotate */
        return (object << count)|(object >> (int_bits - count));
    }
}