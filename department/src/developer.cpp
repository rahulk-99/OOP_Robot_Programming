#include "developer.hpp"
#include <iostream>

// Overridden methods
void company::Developer::perform_task() {
    std::cout << "Developer: perform_task called\n";
}

void company::Developer::attend_meeting() {
    std::cout << "Developer: attend_meeting called\n";
}

void company::Developer::receive_salary(double salary) {
    salary_ = salary;
    std::cout << "Developer: receive_salary called\n";
}

// Additional Developer-specific methods
void company::Developer::write_code(const std::string& language) {
    if (programming_languages_.find(language) != programming_languages_.end()) {
        std::cout << name_ << " is writing code in " << language << ".\n";
    } else {
        std::cout << name_ << " does not know " << language << ".\n";
    }
}

void company::Developer::add_programming_language(const std::string& language) {
    programming_languages_.insert(language);
}

void company::Developer::set_current_project(const std::string& project) {
    current_project_ = project;
}
