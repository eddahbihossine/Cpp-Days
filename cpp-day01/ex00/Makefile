NAME = Zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = $(NAME)
SRCS = main.cpp \
	Zombie.cpp

OBJS = $(SRCS:.cpp=.o)
HEADERS = Zombie.hpp

.PHONY: all clean fclean re

all: $(TARGET)
$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
