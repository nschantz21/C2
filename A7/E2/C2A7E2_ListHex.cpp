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
#include <fstream>      // std::ifstream
#include <iomanip>

using namespace std;

void ListHex(ifstream &inFile, int bytesPerLine)
{
    char buffer;
    cout << setfill('0');
    int outCount = 1;
    
    while(inFile.read(&buffer, 1)) {
        if (inFile.eof())
        {
            break;
        } else {
            cout << setw(2) << hex << (unsigned int) buffer << " ";
            outCount++;
        }
        
        if (outCount % bytesPerLine == 0) {
           cout << "\n" ;
        }
    }
    
    
}
