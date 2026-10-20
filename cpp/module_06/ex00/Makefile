CFLAGS = -Wextra -Werror -Wall -std=c++98
NAME = convert
SRC = ScalarConverter.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) main.cpp
	c++ $(CFLAGS) main.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	c++ $(CFLAGS) -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean