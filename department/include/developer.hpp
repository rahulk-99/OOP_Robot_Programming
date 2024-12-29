/**
 * @file developer.hpp
 * @author1 Masum Thakkar(masumth@umd.edu)
 * @author2 Rahul Kumar(rahulk99@umd.edu)
 * @author3 Tirth Sadaria(tsadaria@umd.edu)
 * 
 * @brief Declaration of the Developer class derived from employee, 
 *        representing a software developer employee in the company.
 * @version 0.1
 * @date 2024-11-11
 * 
 * 
 * @copyright Copyright (c) 2024
 */

#pragma once
#include "employee.hpp"
#include <set>
#include <string>

namespace company{
using ushort = unsigned short;

/**
 * @class Developer
 * @brief Represents a software developer in the company, inheriting from the Employee base class.
 *
 * The Developer class extends the Employee class to include specific attributes and methods
 * related to a software developer's role, such as managing programming languages and current projects.
 */

class Developer : public Employee {
    public:
        /**
        * @brief Constructs a Developer object.
        * @param name The name of the developer.
        * @param salary The salary of the developer.
        * @param badge The IDBadge object associated with the developer.
        */
        Developer(const std::string& name, double salary, const IDBadge& badge): Employee(name, salary, badge) {}

    /**
     * @brief Perform a task specific to a developer.
     *        Prints a message indicating the task is being performed.
     */
    void perform_task() override;

    /**
     * @brief Attend a meeting specific to a developer.
     *        Prints a message indicating the meeting is attended.
     */
    void attend_meeting() override;

    /**
     * @brief Receive the salary for the developer.
     * @param salary The amount of salary to be received.
     *        Prints a message indicating the salary received.
     */
    void receive_salary(double salary) override;

    /**
     * @brief Write code in a specified programming language.
     * @param language The programming language in which the developer writes code.
     */   
    void write_code(const std::string& language);

    /**
     * @brief Add a programming language to the developer's skill set.
     * @param language The programming language to be added.
     */
    void add_programming_language(const std::string& language);

    /**
     * @brief Set the current project the developer is working on.
     * @param project The name of the project.
     */
    void set_current_project(const std::string& project);

    private:
        /**
        * @brief A set of programming languages the developer is proficient in.
         *        Ensures unique entries for the programming languages.
        */
        std::set<std::string> programming_languages_;

        /**
         * @brief The name of the current project the developer is working on.
         */
        std::string current_project_;
};
}