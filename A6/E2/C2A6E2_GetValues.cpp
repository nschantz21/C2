/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-05
 * C2A6E2_GetValues.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Prompt user to input elements white-space separated floating point values.
 * Then read in values with cin. Store values in successive elements of the array
 * "first" starting with element 0. Returns pointer to first element of the array.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

float *GetValues(float *first, size_t elements)
{
    /* prompt user */
    cout << "input elements white-space separated floating point values\n";
    /* iterate over array using pointers and assign elements */
    for (size_t counter = 0; counter < elements; counter++) {
        cin >> *first++;
    }
    /* reset first to point to first element */
    return first - elements;
}
