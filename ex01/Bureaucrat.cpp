#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(Form &form)
{
    if (form.GetState())
    {
        std::cout << "The form is already signed!" << std::endl;
    }
    else
    {
        try
        {
            form.beSigned(*this);
            std::cout << "The bureaucrat " << getName() << " signed the form " << form.GetName() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "The bureaucrat " << getName() << " couldn't sign the form " << form.GetName()
                      << " because: " << e.what() << std::endl;
        }
    }
}


std::ostream& operator<<(std::ostream& os, Bureaucrat &bureaucrat)
{
    os << "Bureaucrat named: " << bureaucrat.getName() 
       << " has a Grade: " << bureaucrat.getGrade() << std::endl;
    return os;
}
