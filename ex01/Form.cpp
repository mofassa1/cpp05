#include "Form.hpp"

Form::Form() : Name("Default"), Signed(false), GradeToSigne(150), GradeToExec(150)
{
}

Form::Form(std::string name, int GradeToSigne, int GradeToExec) : Name(name), Signed(false), GradeToSigne(GradeToSigne), GradeToExec(GradeToExec)
{
    if (GradeToSigne < 1 || GradeToExec < 1)
        throw GradeTooHighException();
    if (GradeToSigne > 150 || GradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : Name(other.Name), Signed(false), GradeToSigne(other.GradeToSigne), GradeToExec(other.GradeToExec)
{
    if (GradeToSigne < 1 || GradeToExec < 1)
        throw GradeTooHighException();
    if (GradeToSigne > 150 || GradeToExec > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
}

Form &Form::operator=(const Form& src)
{
    if (this != &src)
        this->Signed = src.Signed;
    return *this;
}


std::string Form::GetName() const
{
    return Name;
}


bool Form::GetState() const
{
    return Signed;
}


int  Form::GetGradeToSige() const
{
    return GradeToSigne;
}

int  Form::GetGradeToExecute() const
{
    return GradeToExec;
}


void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > GetGradeToSige())
        throw GradeTooLowException();
    else
        Signed = true;
}



const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}


std::ostream& operator<<(std::ostream& os, Form &form)
{
    os << "form named : " << form.GetName() << " it state : " << form.GetState() << " Grade needed to signe : " << form.GetGradeToSige() << " and to execute : " << form.GetGradeToExecute() << std::endl;
    return os;
}




/*
std::ostream& operator<<(std::ostream& os, Form &form);


        // getters
        const std::string GetName() const;
        const bool GetState() const;
        const int  GetGradeToSige() const;
        const int  GetGradeToExecute() const;


*/