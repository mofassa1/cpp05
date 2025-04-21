#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(0));
    try {
        std::cout << "Test 1: ShrubberyCreationForm \n" << std::endl;

        Bureaucrat firstBureaucrat("firstBureaucrat", 140);
        ShrubberyCreationForm shrubForm("Home");
        firstBureaucrat.signForm(shrubForm);
        firstBureaucrat.executeForm(shrubForm);

        std::cout << "\n Test 2: ShrubberyCreationForm \n" << std::endl;

        Bureaucrat SecondBureaucrat("SecondBureaucrat", 130);
        SecondBureaucrat.signForm(shrubForm);
        SecondBureaucrat.executeForm(shrubForm);

        std::cout << "\n Test 3: RobotomyRequestForm \n" << std::endl;

        Bureaucrat ThirdBureaucrat("ThirdBureaucrat", 40);
        RobotomyRequestForm roboForm("TargetA");
        ThirdBureaucrat.signForm(roboForm);
        ThirdBureaucrat.executeForm(roboForm);

        std::cout << "\n Test 4: PresidentialPardonForm \n" << std::endl;

        Bureaucrat LastBureaucrat("LastBureaucrat", 3);
        PresidentialPardonForm pardonForm("brook");
        LastBureaucrat.signForm(pardonForm);
        LastBureaucrat.executeForm(pardonForm);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
