NAME = ex01
C++ = c++

CPPFLAGS = -Wall -Wextra -Werror

SRC = main.cpp \
		Serializer.cpp \

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(C++) $(CPPFLAGS) -o $(NAME) $(OBJ)

fclean :
	rm -rf $(OBJ)

clean :
	rm -rf $(NAME)

re :
	@make clean
	@make all