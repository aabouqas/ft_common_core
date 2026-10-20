CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp Harl.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = Harl

all: $(NAME)

$(NAME): $(OBJ) Harl.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Harl.hpp
	c++ $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean