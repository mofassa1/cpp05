NAME = EX03

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC =  Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)
	
re:fclean all

.SECONDARY: $(OBJ)3