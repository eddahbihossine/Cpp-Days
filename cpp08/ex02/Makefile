NAME = span
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
INC = MutantStack.hpp

C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ) $(INC)
	$(C++) $(CFLAGS) -o $(NAME) $(OBJ)
all: $(NAME)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re