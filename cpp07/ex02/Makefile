NAME = ex02
C++ = c++
CFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp

message = ""

$(message) :
	@echo "jericho hh"
	@sleep 1

OBJS = $(SRCS:.cpp=.o)

all : $(NAME) $(message)

$(NAME) : $(OBJS)
	$(C++) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	@make fclean
	@make all