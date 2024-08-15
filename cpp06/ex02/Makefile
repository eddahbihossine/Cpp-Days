NAME = ex02
C++ = C++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
		Classes.cpp
INC = Base.hpp
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
