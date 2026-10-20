CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) Weapon.hpp HumanA.hpp HumanB.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)
%.o:%.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	c++ $(CFLAGS) -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
.PHONY: clean