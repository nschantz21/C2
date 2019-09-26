#include <stdio.h>

int main(int argc, const char* argv[])
{
    /* print the argument count */
    printf("%d\n", argc);
    /* print each argument value and newline */
    for (int arg = 0; arg < argc; arg++) {
        printf("%s\n", argv[arg]);
    }
    
    return 0;
}
