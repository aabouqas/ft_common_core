CFLAGS = -Wextra -Werror -Wall -std=c++98
NAME = identify
SRC =  Base.cpp A.cpp B.cpp C.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) main.cpp $(SRC=%.cpp:%.h)
	c++ main.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.h
	c++ -c $(CFLAGS) $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
