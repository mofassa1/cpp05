#include "Form.hpp"

int main()
{
    try
    {
        {
            Bureaucrat one(300);
            Bureaucrat two("The Second");

            std::cout << one << std::endl;
            std::cout << two << std::endl; 
        }
        {
            Bureaucrat Tree;
            Form form("Invalid", 1, 300);
            
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception : " << e.what() << std::endl;
    }
    

}