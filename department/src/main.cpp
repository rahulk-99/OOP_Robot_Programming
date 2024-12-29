#include <iostream>
#include <vector>
#include <memory>
#include "manager.hpp"
#include "developer.hpp"
#include "idbadge.hpp"
#include "department.hpp"

int main() {
    // Create ID badges for employees
    company::IDBadge manager_badge("sd12122", company::Date(11, 1, 2013));
    company::IDBadge dev1_badge("pm134798", company::Date(2, 5, 2020));
    company::IDBadge dev2_badge("cn48938", company::Date(15, 6, 2018));

    // Create employees using polymorphism
    std::shared_ptr<company::Employee> manager = std::make_shared<company::Manager>("william", 90000, manager_badge, 0, 3);
    std::shared_ptr<company::Employee> dev1 = std::make_shared<company::Developer>("harry", 70000, dev1_badge);
    std::shared_ptr<company::Employee> dev2 = std::make_shared<company::Developer>("megan", 75000, dev2_badge);

    // Add employees to their respective departments
    company::Department IT_department;
    IT_department.add_employee(manager);

    company::Department cloud_department;
    cloud_department.add_employee(dev1);
    cloud_department.add_employee(dev2);

    // Display employees in each department
    std::cout << "=========================================\n";
    std::cout << "Demonstrating Inheritance:\n";
    std::cout << "=========================================\n";

    std::cout << "Employees in IT Department:\n";
    std::cout << "-----------------------------------------\n";
    IT_department.display_employees();

    std::cout << "-----------------------------------------\n";
    std::cout << "Employees in cloud Department:\n";
    std::cout << "-----------------------------------------\n";
    cloud_department.display_employees();

    std::cout << "=========================================\n";
    std::cout << "Demonstrating Polymorphism:\n";
    std::cout << "=========================================\n";

    // Store employees in a vector for polymorphism demonstration
    std::vector<std::shared_ptr<company::Employee>> employees = {manager, dev1, dev2};

    for (const auto& employee : employees) {
        std::cout << "Info on: " << employee->get_name() << "\n";

        // Badge details (displayed through Employee)
        std::cout << "Badge Info: \n";
        employee->get_badge().display_badge_info();

        // Polymorphic calls
        employee->attend_meeting();
        employee->perform_task();
        employee->receive_salary(50000);

        std::cout << "-----------------------------------------\n";
    }

    std::cout << "=========================================\n";
    std::cout << "Developer Specific Methods:\n";
    std::cout << "=========================================\n";

    // Developer-specific methods
    std::shared_ptr<company::Developer> dev1_specific = std::dynamic_pointer_cast<company::Developer>(dev1);
    dev1_specific->add_programming_language("C++");
    dev1_specific->add_programming_language("Python");
    dev1_specific->write_code("Python"); // Writes code in Python
    dev1_specific->write_code("Java");   // Fails because dev1 doesn't know Java
    dev1_specific->set_current_project("Data analysis");

    std::cout << "=========================================\n";
    std::cout << "Manager Specific Methods:\n";
    std::cout << "=========================================\n";

    // Manager-specific methods
    std::shared_ptr<company::Manager> manager_info = std::dynamic_pointer_cast<company::Manager>(manager);
    
    dev1->set_performance_percentage(85.0);  // Developer 1 performance score
    dev2->set_performance_percentage(65.0);  // Developer 2 performance score

    // Assign team members to the manager
    manager_info->set_team_members({dev1, dev2});
    manager_info->conduct_performance_review();

    std::cout << "=========================================\n";

    return 0;
}