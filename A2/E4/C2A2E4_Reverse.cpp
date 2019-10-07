/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-04
 * C2A2E4_Reverse.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Recursively reads one character at a time from the text file in inFile until
 * a separator is encountered. Those non-separator characters are then displayed
 * in reverse order, with the last and next to next to last characters displayed
 * being capitalized. Finally, the separator is returned to the calling function.
 * Separators are not reversed and are not printed by Reverse, but are instead
 * merely returned.
 */
#include <fstream>
#include <iostream>

using namespace std;

const int CAPLAST = 1;
const int CAPLASTLAST = 3;

inline bool is_separator(int sep)
{
    /* check is character is a separator */
    if (isspace(sep) || (sep == '.') ||
        (sep == '?') || (sep == '!') || 
        (sep == ',') || (sep == ':') ||
        (sep == ';') || (sep == EOF)) {
        return true;
    } else {
        return false;
    }
}

int Reverse(ifstream &inFile, const int level)
{
    /* get next char from file stream */
    int this_char, this_separator;
    this_char = inFile.get();
    /* if the char is a separator return to caller */
    if (is_separator(this_char)) {
        return this_char;
    } else {
        /* recursively call the function with increased level */
        this_separator = Reverse(inFile, level + 1);
    }
    /* capitalize if last or third to last in word */
    if ((level == CAPLAST) || (level == CAPLASTLAST)) {
        this_char = toupper(this_char);
    }
    cout << (char)this_char;
    return this_separator;
}
