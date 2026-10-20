CFLAGS = -Wextra -Werror -Wall -std=c++98
NAME = serializer
SRC = main.cpp Serializer.cpp Data.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(SRC=%.cpp:%.h)
	c++ $(OBJ) -o $(NAME)

%.o: %.cpp %.h
	c++ -c $(CFLAGS) $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
