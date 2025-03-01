#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        std::cout << "Test 1: Bureaucrat tries to execute a ShrubberyCreationForm\n";
        Bureaucrat alice("Alice", 140);
        ShrubberyCreationForm shrubForm("Home");
        alice.signForm(shrubForm);
        alice.executeForm(shrubForm);

        std::cout << "\nTest 2: Bureaucrat with sufficient grade executes ShrubberyCreationForm\n";
        Bureaucrat bob("Bob", 130);
        bob.signForm(shrubForm);
        bob.executeForm(shrubForm);

        std::cout << "\nTest 3: RobotomyRequestForm execution\n";
        Bureaucrat charlie("Charlie", 40);
        RobotomyRequestForm roboForm("TargetX");
        charlie.signForm(roboForm);
        charlie.executeForm(roboForm);

        std::cout << "\nTest 4: PresidentialPardonForm execution\n";
        Bureaucrat dave("Dave", 3);
        PresidentialPardonForm pardonForm("Frank");
        dave.signForm(pardonForm);
        dave.executeForm(pardonForm);
    } 
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
