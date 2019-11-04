/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-05
 * C2A6E3_DisplayClassStatus.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define functions to compare strings, use quicksort algorithm to sort array of strings,
 * and use binary search for finding an element in an array of strings.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int Compare(const void *elemA, const void *elemB)
{
    // use strcmp
    int res = strcmp(*(const char **)elemA, *(const char **)elemB);
    return res;
}


void SortStudents(const char *studentList[], size_t studentCount)
{
    /* quicksort algortihm, each element is a const char pointer */
    qsort(studentList, studentCount, sizeof(const char *), Compare);
}


void DisplayClassStatus(const char *registrants[], size_t registrantCount,
                        const char *attendees[], size_t attendeeCount)
{
    /* find and print names of registrants who did not attend */
    printf("Not present:\n");
    for (size_t rcntr = 0; rcntr < registrantCount; rcntr++) {
        char *res = (char *)bsearch(&registrants[rcntr], attendees,
            attendeeCount, sizeof(const char *), Compare);
        if (res == NULL) {
            printf("%s\n", registrants[rcntr]);
        }
    }
    
    /* find and print names of unregistered attendees */
    printf("Not registered:\n");
    for (size_t acntr = 0; acntr < attendeeCount; acntr++) {
        char *res = (char *)bsearch(&attendees[acntr], registrants,
            registrantCount, sizeof(const char *), Compare);
        if (res == NULL) {
            printf("%s\n", attendees[acntr]);
        }
    }
}
