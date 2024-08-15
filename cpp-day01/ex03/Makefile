NAME = Zombie
CXX = g++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = $(NAME)
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp 

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all