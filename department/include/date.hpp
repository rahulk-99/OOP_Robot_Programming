/**
 * @file date.hpp
 * @author1 Masum Thakkar(masumth@umd.edu)
 * @author2 Rahul Kumar(rahulk99@umd.edu)
 * @author3 Tirth Sadaria(tsadaria@umd.edu)
 * 
 * @brief Declaration of the Date class for representing and validating date values.
 * @version 0.1
 * @date 2024-11-11
 * 
 * 
 * @copyright Copyright (c) 2024
 */

#pragma once
#include<stdexcept>
namespace company{
using ushort = unsigned short;

class Date {
   
   private:

    ushort day_;
    ushort month_;
    ushort year_;

   public:

    Date(ushort day, ushort month, ushort year) {
        if (!is_valid_date(day, month, year)) {
            throw std::invalid_argument("Invalid date provided.");
        }
        day_ = day;
        month_ = month;
        year_ = year;
    }

    void print_date() const;
    /**
     * @brief Print the date in the format month/day/year
     *
     */

    static bool is_leap_year(ushort year);
    /**
     * @brief Check if a year is a leap year
     *
     * @return true
     * @return false
     */
    bool is_valid_date(ushort day, ushort month, ushort year) const;
    /**
     * @brief Function to check if the provided date is valid
     *
     * @param day Given day
     * @param month Given month
     * @param year Given year
     * @return true The passed date is valid
     * @return false The passed date is invalid
     */
    
    ushort get_days_in_month(ushort month, ushort year) const;
    /**
     * @brief Helper function to get the number of days in a given month
     *
     * @param month Given month
     * @param year Given year
     * @return unsigned short Number of days in a given month and in a given year
     */
    

};  // class Date
}  // namespace company