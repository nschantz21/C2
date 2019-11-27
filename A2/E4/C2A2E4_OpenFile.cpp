/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-04
 * C2A2E4_OpenFile.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * OpenFile opens the file named in fileName in the read-only text mode using the inFile
 * object. If the open fails an error message is output to cerr and the program
 * is terminated with an error exit code. The error message must mention the
 * name of the failing file.
 */
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

void OpenFile(const char *filename, ifstream &inFile)
{
    inFile.open(filename);
    /* check if file successfully opened */
    if (!inFile.is_open()) {
        cerr << filename << " failed to open!\n";
        exit(EXIT_FAILURE);
    } else {
        return;
    }
}
