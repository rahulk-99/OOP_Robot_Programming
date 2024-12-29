#include "department.hpp"
#include <iostream>

void company::Department::add_employee(const std::shared_ptr<Employee>& employee) {
    employees_.push_back(employee);
}

// Method to display all employees in the department
void company::Department::display_employees() const {
    for (const auto& employee : employees_) {
        std::cout << "Employee Name: " << employee->get_name() << "\n";
        employee->get_badge().display_badge_info();
    }
}
