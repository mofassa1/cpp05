#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"


int main(void)
{
    Intern AnIntern;
    Bureaucrat boss("Boss", 1);

    std::cout << "===== Test 1: Creating Forms by Intern =====" << std::endl;

    AForm* shrub = AnIntern.makeForm("shrubbery creation", "Home");
    AForm* robotomy = AnIntern.makeForm("robotomy request", "robotom");
    AForm* pardon = AnIntern.makeForm("presidential pardon", "presidentialp");

    std::cout << "===== Test 2: Bureaucrat Signing & Executing Forms =====" << std::endl;
    if (shrub)
    {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }

    if (robotomy)
    {
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
        delete robotomy;
    }

    if (pardon)
    {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }

    AForm* unknown = AnIntern.makeForm("nonexistent form", "Nowhere");

    if (unknown)
    {
        std::cout << "Created unknown form successfully!" << std::endl;
        delete unknown;
    }

    return 0;
}
