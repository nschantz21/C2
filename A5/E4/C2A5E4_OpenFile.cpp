/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-29
 * C2A5E4_OpenFile.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Open file in read-only text mode. Output error message if fails, mentioning
 * the file name
 */

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

void OpenFile(const char *fileName, ifstream &inFile)
{
    inFile.open(fileName);
    /* check if file successfully opened */
    if (!inFile.is_open()) {
        cerr << fileName << " failed to open!\n";
        exit(EXIT_FAILURE);
    } else {
        return;
    }
}
