/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-12
 * C2A7E2_ListHex.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Display contents of file in inFile as one pair of hexadecimal characters per
 * file byte.
 */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ListHex(ifstream &inFile, int bytesPerLine)
{
    char buffer;
    /* set hex format and fill char */
    cout << hex << setfill('0');
    int outCount = 0;
    
    /* read file one byte at a time */
    while (inFile.read(&buffer, 1)) {
        if (inFile.eof()) {
            break;
        } else {
            if (outCount % bytesPerLine == 0) {
                cout << "\n";
            } else if (outCount > 0) {
                /* do not print trailing space at end of output */
                cout << " ";
            }
            /* print byte */
            cout << setw(2) << (unsigned long)(unsigned char)buffer;
            ++outCount;
            /* print new line based on bytesPerLine */
        }
    }
}
