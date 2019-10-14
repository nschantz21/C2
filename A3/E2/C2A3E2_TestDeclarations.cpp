/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-15
 * C2A3E2_TestDeclarations.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Program implements instructor defined declarations to demonstrate Reverse
 * Right-Left rule
 */

void TestDeclarations()
{
    double (*ap)[6] = {0};        //1.
    long long *(**bce)[6];        //2.
    bce = (long long *(**)[6])ap; //3.
    long &rF2(unsigned *delay);   //4.
    double (*&a1)[6] = ap;        //5.
}
