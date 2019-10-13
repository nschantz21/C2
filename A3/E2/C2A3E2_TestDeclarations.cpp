/*
 * 
 */

void TestDeclarations()
{
    double (*ap)[6] = {0};        //1.
    long long *(**bce)[6];        //2.
    bce = (long long *(**)[6])ap; //3.
    long &rF2(unsigned *delay);   //4.
    double (*&a1)[6] = ap;        //5.
}
