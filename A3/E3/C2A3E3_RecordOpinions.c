/*
 * 
 */
#include <stdio.h>

#define ENDPOINT 5
#define TERMINATE 13

void RecordOpinions(void)
{
    int num_of_resp = 2 * ENDPOINT + 1;
    int responses[num_of_resp] = {0};

    int input_num;
    while(true) {
        /* prompt user for ratings of a product */
        printf("%d %d %d\n", -ENDPOINT, ENDPOINT, TERMINATE);
        scanf("%d", &input_num);
        if (input_num == TERMINATE) {
            /* end loop */
            break;
        } else if ((input_num > ENDPOINT) || (input_num < -ENDPOINT)) {
            /* reject input */
            printf("User input outside of range.\n");
        } else {
            /* increment corresponding rating */
            responses[input_num]++;
        }
    }
    /* Display table */
   printf("Rating  Responses\n------  ---------\n");
    for (int resp = 0; resp < num_of_resp; resp++) {
        /* fix padding */
        printf("%d  %d\n", resp, responses[resp]);
    }
}
