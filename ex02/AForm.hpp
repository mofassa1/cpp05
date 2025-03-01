#pragma once


# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string Name;
        bool              Signed;
        const int         GradeToSigne;
        const int         GradeToExec;

    public:
        AForm();
        AForm(const AForm& other);
        AForm &operator=(const AForm& src);
        AForm(std::string name, int GradeToSigne, int GradeToExec);
        virtual ~AForm();

        // getters
        std::string GetName() const;
        bool GetState() const;
        int  GetGradeToSige() const;
        int  GetGradeToExecute() const;


        void beSigned(const Bureaucrat &ureaucrat);

        void execute(Bureaucrat const &executor) const;


        virtual void ToEcecute(Bureaucrat const &executor) const = 0;
        
        class NotSignedException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

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

std::ostream& operator<<(std::ostream& os, AForm *Aform);

