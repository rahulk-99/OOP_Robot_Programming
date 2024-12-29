#include "employee.hpp"
#include<iostream>

// Virtual Destructor
company::Employee::~Employee() {}

void company::Employee::attend_meeting() {
    std::cout << "Employee: attend_meeting called" << '\n';
}

void company::Employee::receive_salary(double salary) {
    std::cout << "Employee: receive_salary called" << '\n';
}