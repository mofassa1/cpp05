

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), Target("DefaultTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), Target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &source) : AForm(source), Target(source.GetTarget())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
    if (this == &other) return *this;
    Target = other.GetTarget();
    return *this;
}


void ShrubberyCreationForm::ToEcecute(Bureaucrat const &executor) const
{
    (void)executor;

    std::ofstream outfile((this->GetTarget() + "_shrubbery").c_str());
    if (!outfile) {
        return;
    }

    std::string stars = "";
    std::string spaces = "                             "; 

    for (size_t i = 0; i < 10; i++)
    {
        outfile << spaces + "/" + stars + "\\" << std::endl;
        stars += "**";

        if (!spaces.empty()) {
            spaces.erase(spaces.size() - 1, 1);
        }
    }

    for (size_t i = 0; i < 4; i++)
    {
        outfile << "                           " << "|||||" << std::endl;
    }

    outfile << std::endl;
    outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::GetTarget() const
{
    return Target;
}


std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm *form)
{
    out << "from :::::: ShrubberyCreationForm" << std::endl;
    out << "the ShrubberyCreationForm named : " << form->GetName() << "\n" << " it require to signe : " << form->GetGradeToSige() << "\n"
        << " and to execute : " << form->GetGradeToExecute() << "\n" << "it target : " << form->GetTarget() << "\n";
    return out;
}