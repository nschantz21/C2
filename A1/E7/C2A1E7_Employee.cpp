#include "C2A1E7_Employee.h"
#include <string.h>
#include <cstdlib>

void Employee::Set(const char *set_name) {
    /* create static variable. it will be deleted otherwise */
    static char *new_name;
    /* dynamically  allocate  exactly  the  amount  of  memory  necessary */
    size_t alloc_size  = strlen(set_name) + 1;
    new_name = (char *) calloc(alloc_size, sizeof(char));
    
    // memcpy
    memcpy(new_name, set_name, alloc_size);
    
    name = new_name;
}
