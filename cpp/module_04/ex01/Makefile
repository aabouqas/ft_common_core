CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) main.cpp
	c++ $(CFLAGS) main.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	c++ $(CFLAGS) -c $<

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean
