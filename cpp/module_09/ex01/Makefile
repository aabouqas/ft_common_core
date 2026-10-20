CXX=c++
CXXFLAGS=-Wextra -Werror -Wall -std=c++98 -fsanitize=address -g
SRC= main.cpp RPN.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME = RPN

all: $(NAME)

$(NAME): $(OBJ) RPN.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp RPN.hpp
	$(CXX) $(CXXFLAGS) -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
