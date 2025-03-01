#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) ,Target("DefaultTarget") 
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) ,Target(target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source), Target(source.GetTarget())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other) return *this;
    Target = other.GetTarget();
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::GetTarget() const
{
    return Target;
}

void RobotomyRequestForm::ToEcecute(Bureaucrat const &executor) const
{
    (void)executor;
    
    if (std::rand() % 2 == 1)
        std::cout << "yoooo hoooo hooo hooooo  " << this->GetTarget() << " was robotomized" << std::endl;
    else
        std::cout << "Robotomy Failed !!!!!!!!!!!!!!!!!! " << std::endl;
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm *form)
{
    out << "from ::::: RobotomyRequestForm" << std::endl;
    out << "the RobotomyRequestForm named : " << form->GetName() << "\n" << " it require to signe : " << form->GetGradeToSige() << "\n"
        << " and to execute : " << form->GetGradeToExecute() << "\n" << "it target : " << form->GetTarget() << "\n";
    return out;
}
