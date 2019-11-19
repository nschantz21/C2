/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-19
 * C2A8E1_OpenFiles.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Dynamically creates an array of ifstream objects having count elements then
 * uses those objects to open the files named in fileNames, in order.
 */

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

static void OpenFile(const char *fileName, ifstream &inFile)
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

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
    /* create array of ifstreams */
    ifstream *filestreams = new ifstream[count];
    for (size_t curr_file = 0; curr_file < count; curr_file++) {
        /* open all  */
        OpenFile(fileNames[curr_file], filestreams[curr_file]);
    }
    
    /* return pointer to first element of filestreams */
    return filestreams;
}
