/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-09-28
 * C2A1E7_Employee.h
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Define Employee class and class getters and setters.
 */

#ifndef C2A1E7_EMPLOYEE_H
#define C2A1E7_EMPLOYEE_H

class Employee {

private:
    /* characteristics of an employee */
    char *name;
    int age;
    float raise;
    double salary;

public:
    /* object handlers */
    
    /* Setters */
    /* name */
    void Set(const char *set_name);
    
    /* age */
    void Set(int input_age = 25) {
        age = input_age;
    }
    
    /* raise */
    void Set(float const &input_raise) {
        raise = input_raise;
    }    
    
    /* salary */
    void Set(double const *input_salary) {
        salary = *input_salary;
    }
    
    /* Getters */
    /* name */
    char *Get(char **get_name) const {
        *get_name = name;
        return name;
    }
    
    /* age */
    int Get(int &get_age) const {
        get_age = age;
        return age;
    }
    
    /* raise */
    float &Get(float &get_raise) {
        get_raise = raise;
        return raise;
    }
    
     /* salary */
    double Get(double *get_salary) const;
    
};

/* you have to decalre inline so the compiler knows it's only defined once */
inline double Employee::Get(double *get_salary) const {
    /* have to cast to double because of constness */
    *get_salary = (double &)salary;
    return (double &)salary;
}

#endif
