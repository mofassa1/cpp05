#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string Target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &source);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        std::string GetTarget() const ;

        void ToEcecute(Bureaucrat const &executor) const;
};
std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm *form);
