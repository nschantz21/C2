/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-15
 * C2A3E3_RecordOpinions.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Program prompts user for their ratings of a product, counts the quantity of
 * each rating, and displays a table of the total quantity of each rating
 */

#include <stdio.h>

#define ENDPOINT 5
#define TERMINATE 999
#define RESPC (2 * ENDPOINT + 1)

void RecordOpinions(void)
{
    int responses[RESPC] = {0};
    for (;;) {
        /* prompt user for ratings of a product */
        printf("Enter values between %d and %d. Use %d to terminate\n",
            -ENDPOINT, ENDPOINT, TERMINATE);
        int input_num;
        scanf("%d", &input_num);
        if (input_num == TERMINATE) {
            /* end loop */
            break;
        } else if ((input_num > ENDPOINT) || (input_num < -ENDPOINT)) {
            /* reject input */
            printf("User input outside of range.\n");
        } else {
            /* increment corresponding rating */
            int *midpoint = &responses[ENDPOINT];
            midpoint[input_num]++;
        }
    }
    /* Display table */
    printf(
        "Rating  Responses\n"
        "------  ---------\n");
    for (int resp = 0; resp < RESPC; resp++) {
        printf("%6d  %9d\n", resp - ENDPOINT, responses[resp]);
    }
}
