#include "C2A1E7_Employee.h"
#include <iostream>
#include <cstring>

using namespace std;

const char * const TEST_NAME = "Elmer Fudd";

int main() {
    
    Employee *employee = new Employee;
    
    // test setting age
    employee->Set();
    int age;
    // get age
    cout << employee->Get(age) << '\n';
    
    // set salary
    double salary = 12456.3654;
    employee->Set(&salary);
    // get salary    
    double *salary2;
    cout << employee->Get(salary2) <<'\n';
    
    // Test setting and getting of employee's name.
    char *nameReturn, *nameOutVar;
    // Make a copy of the test name at a different address in case the
    // programmer only does a shallow copy of the pointer.
    size_t nameLength = strlen(TEST_NAME) + 1;
    
    char *testName = new char [nameLength];
    memcpy(testName, TEST_NAME, nameLength);
    
    employee->Set(testName);
    testName[0] = '\0';
    
    nameReturn = employee->Get(&nameOutVar);
    cout << nameReturn << '\n';
    
    /* test raise */
    
    
    return 0;
}
