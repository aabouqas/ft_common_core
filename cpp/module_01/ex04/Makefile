CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.cpp
	c++ $(CFLAGS) -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
.PHONY: clean
