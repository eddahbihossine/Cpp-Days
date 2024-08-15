NAME = span
SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES = Span.hpp

C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


$(NAME): $(OBJ) $(INCLUDES)
	$(C++) $(CFLAGS) -o $(NAME) $(OBJ)
all: $(NAME)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ)
	rm -f $(NAME)

re : fclean all
.PHONY: all clean fclean re