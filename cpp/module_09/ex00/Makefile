CXX=c++
CXXFLAGS=-Wextra -Werror -Wall -std=c++98
SRC= main.cpp BitcoinExchange.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME = btc

all: $(NAME)

$(NAME): $(OBJ) BitcoinExchange.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp BitcoinExchange.hpp
	$(CXX) $(CXXFLAGS) -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
