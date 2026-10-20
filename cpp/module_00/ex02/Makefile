CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = tests.cpp Account.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = Account

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.cpp Account.hpp
	c++ $(CFLAGS) -c $<
fclean: clean
	rm -rf $(NAME)
clean:
	rm -rf $(OBJ)
.PHONY: clean