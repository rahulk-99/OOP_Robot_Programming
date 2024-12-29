#include "manager.hpp"
#include <iostream>

// Define the method to perform a task specific to the Manager
void company::Manager::perform_task() {
    std::cout << "Manager: perform_task called\n";
}

// Define the method for attending a meeting specific to the Manager
void company::Manager::attend_meeting() {
    std::cout << "Manager: attend_meeting called\n";
}

// Define the method to receive salary specific to the Manager
void company::Manager::receive_salary(double salary) {
    std::cout << "Manager: receive_salary called\n";
}

// Set the team members for the Manager, updating the team size as well
void company::Manager::set_team_members(const std::vector<std::shared_ptr<Employee>>& team_members) {
    this->team_members = team_members;  // Assign to the class member
    team_size_ = static_cast<ushort>(team_members.size());  // Update the team size
}

// Conduct a performance review for each team member
void company::Manager::conduct_performance_review() const {
    std::cout << "Manager conducting performance review........\n";

    // Loop through each team member to evaluate their performance
    for (const auto& member : team_members) {  // Corrected: team_members instead of team_members_
        std::cout << "Reviewing performance of: " << member->get_name() << "\n";
        
        // Placeholder for getting the performance percentage of the employee
        double performance_percentage = member->get_performance_percentage();  // Assuming this method exists in Employee or derived classes
        
        // Evaluate performance based on the percentage
        if (performance_percentage >= 90) {
            std::cout << member->get_name() << " performance: Excellent (" << performance_percentage << "%)\n";
        } else if (performance_percentage >= 70) {
            std::cout << member->get_name() << " performance: Good (" << performance_percentage << "%)\n";
        } else if (performance_percentage >= 50) {
            std::cout << member->get_name() << " performance: Needs Improvement (" << performance_percentage << "%)\n";
        } else {
            std::cout << member->get_name() << " performance: Poor (" << performance_percentage << "%)\n";
        }
    }
}
