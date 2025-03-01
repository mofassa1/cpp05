#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        AForm* makeShrubbery(const std::string& target) const;
        AForm* makeRobotomy(const std::string& target) const;
        AForm* makePresidential(const std::string& target) const;
    
    public:
        Intern();
        Intern(Intern &src);
        Intern &operator=(Intern &src);
        ~Intern();
        AForm *makeForm(const std::string& formName, const std::string& target);
};

