NAME = phonebook
CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =  contact.cpp phonebook.cpp utils.cpp

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp contact.hpp phonebook.hpp
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: fclean all
clean:
	rm -f $(OBJ)