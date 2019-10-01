/*
 * 
 * OpenFile opens the file named in fileName in the read-only text mode using the inFile
 * object. If the open fails an error message is output to cerr and the program
 * is terminated with an error exit code. The error message must mention the
 * name of the failing file.
 */
#include <fstream>
#include <iostream>
using namespace std;

void OpenFile(const char *filename, ifstream &inFile)
{
    inFile.open(filename, ios::in);
    if (!inFile.is_open()) {
        cerr << filename << " failed to open!\n";
    } else {
        return;
    }
}
