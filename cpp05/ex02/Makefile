NAME = ex02
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp  AForm.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp  PresidentialPardonForm.cpp
INC = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp  RobotomyRequestForm.hpp  PresidentialPardonForm.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

