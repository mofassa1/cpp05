#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): Name("Unnamed"), Grade(150)
{

}

Bureaucrat::Bureaucrat(std::string Name, int Grade): Name(Name)
{
    // try
    // {
        setGrade(Grade);
    // }
    // catch (GradeTooHighException& e)
    // {
        // std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
    // catch (GradeTooLowException& e)
    // {
    //     std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
}

Bureaucrat::Bureaucrat(std::string Name): Name(Name), Grade(150)
{

}

Bureaucrat::Bureaucrat(int Grade): Name("Unnamed")
{
    // try
    // {
        setGrade(Grade);
    // }
    // catch (GradeTooHighException& e)
    // {
        // std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
    // catch (GradeTooLowException& e)
    // {
    //     std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
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
    // try
    // {
        setGrade(Grade - 1);
    // }
    // catch (GradeTooHighException& e)
    // {
    //     std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
}

void Bureaucrat::DecrementGrade()
{
    // try
    // {
        setGrade(Grade + 1);
    // }
    // catch (GradeTooLowException& e)
    // {
    //     std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
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
    // try
    // {
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
    // }
    // catch(GradeTooLowException& e)
    // {
    //     std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
    // catch (GradeTooHighException& e)
    // {
    //     std::cerr << "Exception thrown: " << e.what() << std::endl;
    // }
}

void Bureaucrat::signForm(Form &form)
{
    if (form.GetState())
        std::cout << "the form is already signed !!!! " << std::endl;
    else if (getGrade() > form.GetGradeToSige())
    {
        form.beSigned(*this);
        std::cout << "the bureaucrat  : " << getName() << " signed the form : " << form.GetName() << std::endl;
    }
    else
        std::cout << "the bureaucrat  : " << "** " << *this << " **" << " couldn't sign the form : " << "** " << form << " **" << "because" << "it grade ( " << getGrade() << " ) is too low" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat &bureaucrat)
{
    os << "Bureaucrat named: " << bureaucrat.getName() 
       << " has a Grade: " << bureaucrat.getGrade() << std::endl;
    return os;
}
