/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E5_ResizeAlloc.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Program defines a function named AppendFile that returns type int and has two
 * parameters of type “pointer to constant char”, where the first is named inFile
 * and the second is named outFile. Each represents a string that specifies the
 * name of a file, such as file.c, test.txt, MyFile, etc. AppendFile appends 
 * the contents of the file specified by inFile onto the file specified by
 * outFile, creating the output file if it doesn’t already exist.
 *
 */

#include <fstream>
#include <iostream>
using namespace std;

int AppendFile(const char *inFile, const char *outFile) {    
    /* open a file as binary */
    ifstream ifile(inFile, ios::in | ios::binary);
    
    /* check if ifile opens output to cerr if not */
    if (!ifile.is_open()) {
        cerr << -1;
    } else {
        /* open the out file and check it. use ios::app to append to file */
        ofstream ofile(outFile, ios::out | ios::app | ios::binary);
        if (!ofile.is_open()) {
            cerr << -1;
        } else {
            ofile << ifile.rdbuf();
            /* close files to end the funciton */
            ofile.close();    
        }
    }
    ifile.close();
    return 0;
}
