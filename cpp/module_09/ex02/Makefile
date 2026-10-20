CXX=c++
CXXFLAGS=-Wextra -Werror -Wall -std=c++98 -fsanitize=address -g
SRC= main.cpp PmergeMe.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ) PmergeMe.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
