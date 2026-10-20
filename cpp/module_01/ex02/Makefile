CFLAGS = -Wextra -Werror -Wall -std=c++98
all: main
main: main.o
	c++ $(CFLAGS) main.o -o main
main.o: main.cpp
	c++ $(CFLAGS) -c main.cpp
clean:
	rm -f main.o
fclean: clean
	rm -f main