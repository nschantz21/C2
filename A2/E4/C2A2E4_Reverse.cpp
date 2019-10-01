/*
 * 
 * Recursively reads one character at a time from the text file in inFile until
 * a separator is encountered. Those non-separator characters are then displayed
 * in reverse order, with the last and next to next to last characters displayed
 * being capitalized. Finally, the separator is returned to the calling function.
 * Separators are not reversed and are not printed by Reverse, but are instead
 * merely returned. The code in the instructor-supplied driver file is
 * responsible for printing the separators.
 */
#include <fstream>
#include <iostream>

using namespace std;

inline bool is_separator(char sep)
{
    /* check is character is a separator */
    if (
        isspace(sep) ||
        sep == '.' ||
        sep == '?' ||
        sep == '!' ||
        sep == ',' ||
        sep == ':' ||
        sep == ';' ||
        sep == EOF) {
        return true;
    } else {
        return false;
    }
}

int Reverse(ifstream &inFile, const int level)
{
    /* get next char */
    char this_char, this_separator;
    inFile.get(this_char);
    if (is_separator(this_char)) {
        return this_char;
    } else {
         this_separator = Reverse(inFile, level+1);
    }
    
    if (level == 1) {
        this_char = toupper(this_char);
    }
    cout << this_char;
    
    return this_separator;
}
