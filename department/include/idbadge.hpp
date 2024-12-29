/**
 * @file idbadge.hpp
 * @author1 Masum Thakkar(masumth@umd.edu)
 * @author2 Rahul Kumar(rahulk99@umd.edu)
 * @author3 Tirth Sadaria(tsadaria@umd.edu)
 * 
 * @brief Declaration of the IDBadge class, which represents an identification badge issued to an employee.
 * @version 0.1
 * @date 2024-11-11
 * 
 * 
 * @copyright Copyright (c) 2024
 */

#pragma once

#include <string>
#include "date.hpp"

namespace company{
using ushort = unsigned short;
class Date;

/**
 * @class IDBadge
 * @brief Represents an identification badge assigned to an employee in the company.
 */
class IDBadge {
     
    public:
        /**
        * @brief Constructor for the IDBadge class.
        * @param badgenumber A unique string representing the badge number.
        * @param issuedate The date when the badge was issued.
        */
        IDBadge(const std::string& badgenumber, company::Date issuedate)
            : badge_number_(badgenumber), issue_date_(issuedate) {}

        /**
        * @brief Display the badge information, including badge number and issue date.
        *        Example output: "Badge 123DF33 was issued on 2/22/2022".
        */
        void display_badge_info() const;
    
    private:
        /**
         * @brief The unique identifier for the badge.
        *        This attribute stores the badge number as a string.
        */
        std::string badge_number_;

        /**
        * @brief The date when the badge was issued.
        *        This attribute stores the issue date using the Date class.
        */
        company::Date issue_date_;
};
}