#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &src)
{
    (void)src;
}

Intern &Intern::operator=(Intern &src)
{
    (void)src;
    return *this;
}

AForm* Intern::makeShrubbery(const std::string& target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm* (Intern::*formsToCreate[])(const std::string&) const = { &Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential };

    for (size_t i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formsToCreate[i])(target);
        }
    }

    std::cout << "the Form : '" << formName << "' not found " << std::endl;
    return NULL;
}


Intern::~Intern()
{
}
