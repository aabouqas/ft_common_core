CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = FragTrap

all: $(NAME)

$(NAME): $(OBJ) ClapTrap.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	c++ -c $(CFLAGS) $<

re : fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean