#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"


int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    std::cout << "\n===== Test 1: Creating Forms via Intern =====\n";
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Alice");

    std::cout << "\n===== Test 2: Bureaucrat Signing & Executing Forms =====\n";
    if (shrub) {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }

    if (robotomy) {
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
        delete robotomy;
    }

    if (pardon) {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }

    // Optional test for unknown form
    AForm* unknown = someRandomIntern.makeForm("nonexistent form", "Nowhere");
    if (unknown) {
        std::cout << "Created unknown form successfully!" << std::endl;
        delete unknown;
    }

    return 0;
}
