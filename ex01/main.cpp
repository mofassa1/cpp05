#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        
        std::cout << "Test 1:*****************************************************" << std::endl;
        
        Bureaucrat B1("B1", 50);
        Form taxForm("Tax Form", 40, 30);
        std::cout << B1 << std::endl;
        std::cout << taxForm << std::endl;
        B1.signForm(taxForm);

        std::cout << "Test 2:*****************************************************" << std::endl;
        
        Bureaucrat b2("b2", 30);
        std::cout << b2;
        b2.signForm(taxForm); 
        std::cout << taxForm;

        std::cout << "Test 3:*****************************************************" << std::endl;
        b2.signForm(taxForm);

        std::cout << "Test 4:*****************************************************" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form invalidForm("Document", 0, 30); 
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "Test 5:*****************************************************" << std::endl;
    
    try
    {
        Form invalidForm("Document", 151, 30); 
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
