CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp 
OBJ = $(SRC:%.cpp=%.o)
NAME = Zombie

all: $(NAME)

$(NAME): $(OBJ) Zombie.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Zombie.hpp
	c++ $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean
