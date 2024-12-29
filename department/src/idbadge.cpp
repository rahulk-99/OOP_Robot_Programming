#include "idbadge.hpp"
#include <iostream>

namespace company {

// Definition of the display_badge_info method
void company::IDBadge::display_badge_info() const {
    std::cout << "Badge " << badge_number_ << " was issued on ";
    issue_date_.print_date();  // Use the Date class method to print the date
}

}  // namespace company
