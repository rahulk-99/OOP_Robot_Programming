/**
 * @file employee.hpp
 * @author1 Masum Thakkar(masumth@umd.edu)
 * @author2 Rahul Kumar(rahulk99@umd.edu)
 * @author3 Tirth Sadaria(tsadaria@umd.edu)
 * 
 * @brief Employee is the base abstract class for derived classes 
 * developer and manager as it has one oure virtual method.
 * @version 0.1
 * @date 2024-11-11
 * 
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include<string>
#include<memory>
#include<idbadge.hpp>
namespace company{
using ushort = unsigned short;
class IdBadge;
/**
 * @class Employee
 * @brief Represents an employee in the company.
 * 
 * Employee class is an abstract class that contains information like name, salary, and ID badge of the employee.
 * It hasvirtual methods for employee tasks, attending meetings, and receiving salaries, which are to be overridden by derived classes Manager and Developer.
 * The class also includes a method to set the performance percentage of the employee which is used in manager class for perfomance review.
 */
class Employee{
    public:
   /**
     * @brief Constructor to initialize employee with a name, salary, and an ID badge.
     * 
     * @param name name of the employee.
     * @param salary salary of the employee.
     * @param badge ID badge associated with the employee.
     */
    Employee(const std::string& name, double salary, const IDBadge& badge)
            : name_{name}, salary_{salary}, id_badge_{badge} {}

    /**
     * @brief Pure virtual method to perform the employee's tasks. 
     * This method is overridden by both derived class.
     */
    virtual void perform_task() = 0;

    /**
     * @brief Virtual method for the employee to attend a meeting. 
     * This is overridden by both classes
     */      
    virtual void attend_meeting(); 

    /**
     * @brief Virtual method for the employee to receive their salary.
     * This method is overridden by both classes
     * 
     * @param salary The amount that is received by the employee.
     */       
    virtual void receive_salary(double salary);       
    
    /**
     * @brief Virtual destructor for the Employee class. 
     * Ensures proper cleanup for derived classes when an object is destroyes
     */
    virtual ~Employee();

    /**
     * @brief Getter for the employee's name.
     * 
     * @return The name of the employee.
     */
    std::string get_name() const { return name_; }
    /**
     * @brief Getter for the employee's ID badge.
     * 
     * @return The employee's ID badge.
     */
    const IDBadge& get_badge() const { return id_badge_; }
     /**
     * @brief Getter for the employee's performance percentage.
     * 
     * @return The performance percentage of the employee.
     */
    double get_performance_percentage() const { return performance_percentage_; }
    /**
     * @brief Setter for the employee's performance percentage.
     * 
     * @param percentage The performance percentage to set.
     */
    
    void set_performance_percentage(double percentage) { performance_percentage_ = percentage; }

    protected:
    /**
     * @brief name attribute of the employee 
     * 
     */
    std::string name_;
    /**
     * @brief salary attribute of the employee 
     * 
     */
    double salary_;
    /**
     * @brief object from the class IdBadge 
     * 
     */
    IDBadge id_badge_;  
    /**
     * @brief performance percentage of the employee 
     * 
     */
    double performance_percentage_;

};  // class Employee
}  // namespace company