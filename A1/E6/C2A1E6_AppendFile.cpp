/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E6_AppendFile.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Program to concatenate one file to another. Create the output file if is does
 * not yet exist. Works with both text and binary files.
 */

#include <fstream>
#include <iostream>
using namespace std;

int AppendFile(const char *inFile, const char *outFile)
{    
    /* open a file as binary */
    ifstream ifile(inFile, ios::in | ios::binary);
    
    /* check if ifile opens output to cerr if not */
    if (!ifile.is_open()) {
        cerr << -1;
    } else {
        /* open the out file and check it. use ios::app to append to file */
        ofstream ofile(outFile, ios::out | ios::app | ios::binary);
        if (!ofile.is_open()) {
            ifile.close();
            cerr << -1;
        } else {
            ofile << ifile.rdbuf();
            /* close files to end the function */
            ofile.close();
            ifile.close();            
        }
    }
    return 0;
}
