#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "Test 1: Bureaucrat with insufficient grade trying to sign\n";
    Bureaucrat alice("Alice", 50);
    Form taxForm("Tax Form", 40, 30);
    std::cout << alice;
    std::cout << taxForm;
    alice.signForm(taxForm); // Should fail

    std::cout << "\nTest 2: Bureaucrat with sufficient grade signing the form\n";
    Bureaucrat bob("Bob", 30);
    std::cout << bob;
    bob.signForm(taxForm); // Should succeed
    std::cout << taxForm;

    std::cout << "\nTest 3: Trying to sign an already signed form\n";
    bob.signForm(taxForm); // Should print that it's already signed

    std::cout << "\nTest 4: Creating a form with an invalid grade (too high)\n";
    try {
        Form invalidForm("Secret Doc", 0, 30); // Should throw an exception
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTest 5: Creating a form with an invalid grade (too low)\n";
    try {
        Form invalidForm("Confidential", 151, 30); // Should throw an exception
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
