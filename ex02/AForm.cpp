#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : Name("Default"), Signed(false), GradeToSigne(150), GradeToExec(150)
{
}

AForm::AForm(std::string name, int GradeToSigne, int GradeToExec) : Name(name), Signed(false), GradeToSigne(GradeToSigne), GradeToExec(GradeToExec)
{
    if (GradeToSigne < 1 || GradeToExec < 1)
        throw GradeTooHighException();
    if (GradeToSigne > 150 || GradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : Name(other.Name), Signed(false), GradeToSigne(other.GradeToSigne), GradeToExec(other.GradeToExec)
{
    if (GradeToSigne < 1 || GradeToExec < 1)
        throw GradeTooHighException();
    if (GradeToSigne > 150 || GradeToExec > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm& src)
{
    if (this != &src)
        this->Signed = src.Signed;
    return *this;
}


std::string AForm::GetName() const
{
    return Name;
}


bool AForm::GetState() const
{
    return Signed;
}


int  AForm::GetGradeToSige() const
{
    return GradeToSigne;
}

int  AForm::GetGradeToExecute() const
{
    return GradeToExec;
}


void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > GetGradeToSige())
        throw GradeTooLowException();
    else
        Signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->GetState() == false)
        throw NotSignedException();
    else if (executor.getGrade() > this->GetGradeToExecute())
        throw GradeTooLowException();
    else
        ToEcecute(executor);
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "the form cannot be ececuted because it is not signed yet !!!!! ";
}

std::ostream& operator<<(std::ostream& out, AForm *form)
{
    out << "form ::::::  Aform" << std::endl;
    out << "the form named : " << form->GetName() << std::endl;
    out << " it require to signe : " << form->GetGradeToSige() << std::endl;
    out << " and to execute : " << form->GetGradeToExecute() << std::endl;

    if (form->GetState() == true)
        out << "it is signded " << std::endl;
    else
        out << "it is not signded " << std::endl;
    return out;

}

