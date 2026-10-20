CFLAGS = -Wextra -Werror -Wall -std=c++98
NAME = megaphone

all: $(NAME)

$(NAME): $(NAME).o
	c++ $(CFLAGS) $(NAME).o -o $(NAME)

$(NAME).o: $(NAME).cpp
	c++ $(CFLAGS) -c $(NAME).cpp

re: clean all

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

.PHONY: clean
