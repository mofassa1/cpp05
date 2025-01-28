#pragma once

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string Name;
        bool              Signed;
        const int         GradeToSigne;
        const int         GradeToExec;

    public:
        Form();
        Form(const Form& other);
        Form &operator=(const Form& src);
        Form(std::string name, int GradeToSigne, int GradeToExec);
        ~Form();

        // getters
        std::string GetName() const;
        bool GetState() const;
        int  GetGradeToSige() const;
        int  GetGradeToExecute() const;


        void beSigned(const Bureaucrat &ureaucrat);

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

std::ostream& operator<<(std::ostream& os, Form &form);

