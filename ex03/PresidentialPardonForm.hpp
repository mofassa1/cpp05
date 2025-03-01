#pragma once
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
    private:
        std::string Target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &source);
        PresidentialPardonForm &operator=(PresidentialPardonForm &other);

        ~PresidentialPardonForm();
        std::string GetTarget() const;
        void ToEcecute(Bureaucrat const &executor) const;

};
std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm *form);

