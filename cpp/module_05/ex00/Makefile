CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = Bureaucrat.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) Bureaucrat.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Bureaucrat.hpp
	c++ $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
