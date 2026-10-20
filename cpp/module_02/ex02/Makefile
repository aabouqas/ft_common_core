CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = Fixed

all: $(NAME)

$(NAME): $(OBJ) Fixed.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Fixed.hpp
	c++ $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean
