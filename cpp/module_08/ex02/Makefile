CXX=c++
CXXFLAGS=-Wextra -Werror -Wall -std=c++98
SRC= main.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) MutantStack.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp MutantStack.hpp
	$(CXX) $(CXXFLAGS) -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
