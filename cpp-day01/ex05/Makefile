NAME = Harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = Harl.hpp

TARGET = $(NAME)
SRCS = main.cpp \
		Harl.cpp \

OBJS = $(SRCS:.cpp=.o)

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
