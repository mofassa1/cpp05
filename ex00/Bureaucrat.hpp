#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string Name;
        int               Grade;
    public:
        // constructors
        Bureaucrat();
        Bureaucrat(std::string Name, int Grade);
        Bureaucrat(std::string Name);
        Bureaucrat(int Grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &src);
        // destructor
        ~Bureaucrat();

        // getters
        const std::string getName() const;
        int               getGrade() const;

        // increment / decrement the Grade value
        void              IncrementGrade();
        void              DecrementGrade();

        // setter
        void setGrade(int Grade);
    
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat &bureaucrat);
