/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E2_main.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Display a count of the number of command line arguments that were present when
 * the program was started followed by those arguments in their original order
 * starting with argv[0] . The count and each argument must be displayed alone
 * on separate lines.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* print the argument count */
    printf("%d\n", argc);
    /* print each argument value and newline */
    for (int arg = 0; arg < argc; arg++) {
        printf("%s\n", argv[arg]);
    }
    
    return 0;
}
