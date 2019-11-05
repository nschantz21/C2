/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-05
 * C2A6E4_List.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 *
 * define functions CreateList, PrintList, and FreeList.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C2A6E4_List-Driver.h"

#define BUFSIZE 24

static void *SafeMalloc(size_t size)
{
    /* allocate memory and check for safety */
    void *vp;
    if ((vp = malloc(size)) == NULL) {
        fputs("Out of Memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

static List *NewList()
{
    List *ptr;
    ptr = (List *)SafeMalloc(sizeof(List));
    return(ptr);
}

List *CreateList(FILE *fp)
{
    /* create list */
    List *head = NULL;
    
    char buffer[BUFSIZE];
    /* attempt to read string from file */
    while (fscanf(fp, "%23s", buffer) != EOF) {
        /* iterate over List values */
        int found = 0;
        for (List *ptr = head; ptr != NULL; ptr = ptr->next) {
            /* if in list */
            if (strcmp(ptr->str, buffer) == 0) {
                found = 1;
                ptr->count++;
                break;
            }
        }
        
        if (found != 1) {
            List *new_node = NewList();
            char *new_str;
            size_t alloc_size = strlen(buffer) + 1;
            new_str = (char *)SafeMalloc(alloc_size);
            /* point the node's char pointer to that allocation and copy string into it */
            new_node->str = new_str;
            memcpy(new_str, buffer, alloc_size);
            /* set node's string count to 1 */
            new_node->count = 1;
            /* push node onto the head of the list */
            new_node->next = head;
            head = new_node;
        }
    }
    /* return List head pointer */
    return head;
}

List *PrintList(const List *head)
{
    for (const List *ptr = head; ptr != NULL; ptr = ptr->next) {
        /* added padding to make int align */
        printf("%-14s %6d ea\n", ptr->str, ptr->count);
    }
    return (List *)head;
}

void FreeList(List *head)
{
    /* free all the string allocations in List */
    for (List *p = head; p != NULL;) {
        /* free string */
        List *ptr = p;
        p = p->next;
        /* free current node string */
        free(ptr->str);
        /* free current node */
        free(ptr);
    }
}
