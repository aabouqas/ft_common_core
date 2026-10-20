CXX=c++
CXXFLAGS=-Wextra -Werror -Wall -std=c++98
SRC= main.cpp Span.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME = span

all: $(NAME)

$(NAME): $(OBJ) Span.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
