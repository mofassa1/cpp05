#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) , Target("DefaultTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , Target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &source) : AForm(source) , Target(source.GetTarget())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
    if (this == &other) return *this;
    Target = other.GetTarget();
    return *this;
}

void PresidentialPardonForm::ToEcecute(Bureaucrat const &executor) const
{
    (void)executor;
    std::cout << this->GetTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::GetTarget() const
{
    return Target;
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm *form)
{
    out << "from PresidentialPardonForm" << std::endl;
    out << "the PresidentialPardonForm named : " << form->GetName() << std::endl;
    out << " it require to signe : " << form->GetGradeToSige() << std::endl;
    out << " and to execute : " << form->GetGradeToExecute() << std::endl;
    out << "it target : " << form->GetTarget() << std::endl;
    if (form->GetState() == true)
        out << "it is signded " << std::endl;
    else
        out << "it is not signded " << std::endl;
    return out;
}
