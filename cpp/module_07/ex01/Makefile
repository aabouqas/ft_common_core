CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS= main.cpp
SRCS_O= $(SRCS:.cpp=.o)
NAME= main

all: $(NAME)

$(NAME): $(SRCS_O) iter.hpp
	$(CXX) $(CXXFLAGS) $(SRCS_O) -o $(NAME)

%.o: %.cpp iter.hpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f $(SRCS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
