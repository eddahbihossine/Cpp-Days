NAME = ex00
C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp

INC =  Whatever.hpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(C++) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
