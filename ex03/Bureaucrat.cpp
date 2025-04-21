#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): Name("Unnamed"), Grade(150)
{

}

Bureaucrat::Bureaucrat(std::string Name, int Grade): Name(Name)
{
        setGrade(Grade);
}

Bureaucrat::Bureaucrat(std::string Name): Name(Name), Grade(150)
{

}

Bureaucrat::Bureaucrat(int Grade): Name("Unnamed")
{
        setGrade(Grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : Name(other.Name), Grade(other.Grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->Grade = other.Grade;
    }
    return *this;
}

// destructor
Bureaucrat::~Bureaucrat()
{

}

// getters
const std::string Bureaucrat::getName() const
{
    return Name;
}

int Bureaucrat::getGrade() const
{
    return Grade;
}

// increment / decrement the Grade value
void Bureaucrat::IncrementGrade()
{
        setGrade(Grade - 1);
}

void Bureaucrat::DecrementGrade()
{
        setGrade(Grade + 1);
}

// Grade exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

// Set grade method
void Bureaucrat::setGrade(int Grade)
{
        if (Grade < 1)
        {
            this->Grade = 1;
            throw GradeTooHighException();
        }
        else if (Grade > 150)
        {
            this->Grade = 150;
            throw GradeTooLowException();
        }
        else
            this->Grade = Grade;
}



void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat :" << Name << "  signed the form : " << form.GetName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "Bureaucrat :" << Name << " couldn't sign the form : " << form.GetName() << " because the lowest grade to sign is " << form.GetGradeToSige() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm  &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat : " << this->Name << " executed the form : " << form.GetName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureaucrat : " << this->Name << " couldn't execute the form : " << form.GetName() << " because: " << e.what() << std::endl;
	} 
}

std::ostream& operator<<(std::ostream& out, Bureaucrat *bureaucrat)
{
    out << "form ::::: Bureaucrat " << std::endl;
    out << "Bureaucrat named: " << bureaucrat->getName() << std::endl;
    out << " has a Grade: " << bureaucrat->getGrade() << std::endl;
    return out;
}
