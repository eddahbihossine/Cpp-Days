NAME = ex00
SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)
INCLUDES = Easyfind.hpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all