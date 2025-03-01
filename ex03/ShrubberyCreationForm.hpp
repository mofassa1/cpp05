#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>



class ShrubberyCreationForm : public AForm
{
    private:
        std::string Target;
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm &source);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        std::string GetTarget() const;

        void ToEcecute(Bureaucrat const &executor) const;
};
std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm *form);
