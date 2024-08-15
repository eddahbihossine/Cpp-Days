NAME = ex00
C++ = C++

CPPFLAGS = -Wall -Wextra -Werror 

SRC = main.cpp \
		ScalarConverter.cpp
INC = ScalarConverter.hpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(C++) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : 
	@make clean
	@make all