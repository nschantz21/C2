/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-10-29
 * C2A5E4_DetectFloats.cpp
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Analyzes the string in chPtr and determines if it represents a syntactically
 * legal decimal floating literal, and if so, its data type (but not its value).
 */

#include "C2A5E4_StatusCode-Driver.h"
#include <iostream>
using namespace std;

StatusCode DetectFloats(const char *chPtr)
{
    enum States {
        START,
        NO_WHOLE,
        WHOLE,
        FRACT,
        EXPONENT_PREFIX,
        EXPONENT,
        LDOUBLE,
        FLOAT
    } machine_state = START;
    
    StatusCode return_status = NO_MATCH;
    
    for (int i = 0; chPtr[i] != '\0'; i++) {
        int inChar = chPtr[i];
        
        switch (machine_state)
        {
            case START:
                switch (inChar) {
                    case '.':
                        machine_state = NO_WHOLE;
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        machine_state = WHOLE;
                        break;
                    default:
                        return NO_MATCH;
                        break;
                }
                break;
                
            case NO_WHOLE:
            
                switch (inChar) {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        machine_state = FRACT;
                        return_status = TYPE_DOUBLE;
                        break;
                    /* failure */
                    default:
                        return NO_MATCH;
                        break;
                }
                break;
                
            case WHOLE:
                
                switch (inChar) {
                    case '.':
                        machine_state = FRACT;
                        return_status = TYPE_DOUBLE;
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        /* nothing happens */
                        break;

                    /* exponent */
                    case 'e':
                    case 'E':
                        machine_state = EXPONENT_PREFIX;
                        break;
                    /* failure */
                    default:
                        return NO_MATCH;
                        break;
                }
                
                break;
                
            case FRACT:
            
                switch (inChar) {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        /* nothing happens */
                        break;
                    case 'e':
                    case 'E':
                        machine_state = EXPONENT_PREFIX;
                        return_status = NO_MATCH;
                        break;
                    /* float */
                    case 'f':
                    case 'F':
                        machine_state = FLOAT;
                        return_status = TYPE_FLOAT;
                        break;
                    /* long double */
                    case 'l':
                    case 'L':
                        // return TYPE_LDOUBLE;
                        machine_state = LDOUBLE;
                        return_status = TYPE_LDOUBLE;
                        break;
                    /* failure */
                    default:
                        return NO_MATCH;
                        //return NO_MATCH;
                        break;
                }
                break;
                
            case EXPONENT_PREFIX:
            
                switch (inChar) {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        machine_state = EXPONENT;
                        return_status = TYPE_DOUBLE;
                        break;
                    /* positivity */
                    case '+':
                    case '-':
                        machine_state = EXPONENT;
                        return_status = NO_MATCH;
                        break;
                    /* failure */
                    default:
                        return NO_MATCH;
                        break;
                }
            
                break;
            
            case EXPONENT:
            
                switch (inChar) {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        return_status = TYPE_DOUBLE;
                        /* nothing happens */
                        break;
                    /* float */
                    case 'f':
                    case 'F':
                        machine_state = FLOAT;
                        return_status = TYPE_FLOAT;
                        break;
                    /* long double */
                    case 'l':
                    case 'L':
                        machine_state = LDOUBLE;
                        return_status = TYPE_LDOUBLE;
                        break;
                    /* failure */
                    default:
                        return NO_MATCH;
                        break;
                }
                break;
                
            case LDOUBLE:
                switch (inChar) {
                    default:
                        return NO_MATCH;
                        break;
                }
                break;
            
            case FLOAT:
                switch (inChar) {
                    default:
                        return NO_MATCH;
                        break;
                }
                break;
            default:
                return NO_MATCH;
        }
        
    }
    
    return return_status;
}
