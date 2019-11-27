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

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
    /* create array of ifstreams */
    ifstream *filestreams = new ifstream[count];
    for (size_t curr_file = 0; curr_file < count; curr_file++) {
		/* open file and check if open */
        filestreams[curr_file].open(fileNames[curr_file]);
		if (!filestreams[curr_file].is_open()) {
			cerr << fileNames[curr_file] << " failed to open!\n";
			while (curr_file > 0) {
                filestreams[curr_file].close();
                --curr_file;
			}
			/* delete allocation */
			delete[] filestreams;
			exit(EXIT_FAILURE);
		}
    }
    
    /* return pointer to first element of filestreams */
    return filestreams;
}
