CFLAGS = -std=c++98 -Wextra -Werror -Wall 
SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = Zombie

all: $(NAME)

$(NAME): $(OBJ) Zombie.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Zombie.hpp
	c++ $(CFLAGS) -c $<

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean
