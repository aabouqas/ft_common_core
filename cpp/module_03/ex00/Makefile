CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = ClapTrap

all: $(NAME)

$(NAME): $(OBJ) ClapTrap.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp ClapTrap.hpp
	c++ -c $(CFLAGS) $<

re : fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean