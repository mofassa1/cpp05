#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("one", 50);
        std::cout << b1;

        Bureaucrat b2("two", 1);
        std::cout << b2;
        b2.IncrementGrade(); 

    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("tree", 200); 
        std::cout << b3;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
