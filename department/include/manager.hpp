/**
 * @file manager.hpp
 * @author1 Masum Thakkar(masumth@umd.edu)
 * @author2 Rahul Kumar(rahulk99@umd.edu)
 * @author3 Tirth Sadaria(tsadaria@umd.edu)
 * 
 * @brief Declaration of the Manager class, derived from the Employee class. 
 *        This class models a manager's responsibilities, including task management,
 *        meeting attendance, salary reception, team management, and performance reviews.
 * @version 0.1
 * @date 2024-11-11
 * 
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once
#include "employee.hpp"  // Include Employee base class header
#include <vector>
#include <memory>

namespace company {
    using ushort = unsigned short;

    /**
     * @class Manager
     * @brief Represents a manager in a company, with responsibilities for supervising a team
     *        and overseeing projects. Inherits from the Employee class.
     */
    class Manager : public Employee {  
    public:
        /**
         * @brief Constructor for the Manager class.
         * @param name The name of the manager.
         * @param salary The salary of the manager.
         * @param badge The IDBadge associated with the manager.
         * @param team_size The number of people the manager supervises.
         * @param number_of_projects The number of projects the manager is overseeing.
         */
        Manager(const std::string& name, double salary, const IDBadge& badge, ushort team_size, ushort number_of_projects)
            : Employee(name, salary, badge), team_size_{team_size}, number_of_projects_{number_of_projects}{}

        /**
         * @brief Override the perform_task method from Employee.
         *        This method is responsible for the manager's task execution.
         */
        void perform_task() override;

        /**
         * @brief Override the attend_meeting method from Employee.
         *        This method simulates the manager attending a meeting.
         */
        void attend_meeting() override;

        /**
         * @brief Override the receive_salary method from Employee.
         *        This method handles the manager receiving their salary.
         * @param salary The amount of salary to be received.
         */
        void receive_salary(double salary) override;

        /**
         * @brief Set the team members that the manager supervises.
         * @param team A vector of shared pointers to Employee objects representing the team members.
         */
        void set_team_members(const std::vector<std::shared_ptr<Employee>>& team);

        /**
         * @brief Conduct a performance review for the manager's team.
         *        This method represents a task typically handled by managers.
         */
        void conduct_performance_review() const;

        /**
         * @brief Set the performance percentage for employees in the manager's team.
         * @param employee A vector of shared pointers to Employee objects.
         * @param percentage The performance percentage to be set for the employees.
         */
        void set_performance_percentage(const std::vector<std::shared_ptr<Employee>>& employee, double percentage);

    private:

        /**
         * @brief The number of people the manager supervises.
         *        This attribute represents the size of the team that the manager is responsible for.
         * @note This is a private member of the Manager class.
         */
        ushort team_size_;

        /**
         * @brief The number of projects the manager is overseeing.
         *        This attribute holds the count of the ongoing projects under the manager's supervision.
         * @note This is a private member of the Manager class.
         */
        ushort number_of_projects_;

        /**
         * @brief A vector of shared pointers to Employee objects representing the manager's team members.
         *        This attribute holds all the employees that report to the manager.
         * @note This is a private member of the Manager class.
         */
        std::vector<std::shared_ptr<Employee>> team_members;
    };  // class Manager
}  // namespace company
