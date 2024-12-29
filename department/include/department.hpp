/**
 * @file department.hpp
 * @author1 Masum Thakkar(masumth@umd.edu)
 * @author2 Rahul Kumar(rahulk99@umd.edu)
 * @author3 Tirth Sadaria(tsadaria@umd.edu)
 * 
 * @brief This is the Department class which aggregates multiple employees through shared pointers.
 * This class manages the employees in each department. 
 * It uses the aggregation principle of OOP so department does not own any employees.
 * @version 0.1
 * @date 2024-11-11
 * 
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once
#include <vector>
#include <memory>
#include "employee.hpp"

namespace company{

    /**
     * @class Department
     * @brief Represents a department within a company.
     * 
     * The department class provides the functionality to add employees to the department 
     * and display all employees currently in the department through shared pointers. 
     */

class Department {

    public:
    /**
     * @brief Default constructor for the Department class.
     * 
     * Initializes the department with an empty employee list.
     */
     Department() = default;
    /**
     * @brief this method uses shared pointers to add employee to the list of employees
     * 
     * push_back() method is used to add the employee.
     * 
     * @param employee is a shared pointer to employee to be added.
    */
    void add_employee(const std::shared_ptr<company::Employee>& employee);

    /**
     * @brief This method display the list of employees in the department. 
     * 
     * It also displays the emloyee's badge number and their issue date.
     * 
     * This method uses get_name from employee class to print employeee name and 
     * display_badge_info() to print the badge number and its issue date.
    */
    void display_employees() const;
    
    private:
    /**
     * @brief employee attribute fthat stores all employees as shared pointers
     */
    std::vector<std::shared_ptr<company::Employee>> employees_;
};
}