/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-30
 * C2A1E7_Employee.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define Employee class overloaded method Set for name attribute.
 */

#include "C2A1E7_Employee.h"
#include <cstring>
#include <cstdlib>

void Employee::Set(const char *set_name)
{
    /* dynamically  allocate  exactly  the  amount  of  memory  necessary */
    char *new_name;
    size_t alloc_size = strlen(set_name) + 1;
    new_name = new char[alloc_size];
    /* copy memory into new static variable */
    memcpy(new_name, set_name, alloc_size);
    /* set attribute to point to new static variable's memory */
    name = new_name;
}
