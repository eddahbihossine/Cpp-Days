NAME = ex01
C++ = c++
CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \

# message = "isma3uni"x

OBJS = $(SRCS:.cpp=.o)

#write a message
$(message) :
	@echo "isma3uni "
	@sleep 1
all : $(NAME) $(message)


$(NAME) : $(OBJS) 
	$(C++) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean	
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all