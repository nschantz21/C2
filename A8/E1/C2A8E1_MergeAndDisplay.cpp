/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-19
 * C2A8E1_MergeAndDisplay.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Proceeding in order from the first file specified in files, the first line in 
 * each file is read and When the end of any file is reached that file is closed 
 * and the process continues using only the remaining open files until all files 
 * have finally been closed. Empty lines are displayed as empty lines. Empty files
 * are simply closed and ignored.
 */
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

const int MAXBUFF = 512;
const int SAFEBUF = MAXBUFF - 1;

void MergeAndDisplay(ifstream files[], size_t count) {
    /* iterate over files */
    /* stop when they are all closed */
    int open_count = count;
    char * buffer = new char[MAXBUFF];
    while (open_count > 0) {
        for (size_t cf = 0; cf < count; cf++) {
            /* check if file is open, skip if not */
            if (files[cf].is_open()) {

                fscanf(files[cf], "%s", buffer);
                /* check if file is empty */
                if (strlen(buffer) == 0) {
                    /* if empty skip and close */
                    files[cf].close();
                    open_count--;
                }
                if ((strlen(buffer) != 0) && (buffer != NULL)) {
                    cout << buffer << '\n';
                }
            }
        }
    }
    delete buffer;
}
