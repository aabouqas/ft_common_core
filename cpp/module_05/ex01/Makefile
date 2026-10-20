# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 13:00:42 by aabouqas          #+#    #+#              #
#    Updated: 2024/10/09 13:00:44 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp Form.cpp Bureaucrat.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) Bureaucrat.hpp Form.hpp
	c++  $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile
	c++ -c $(CFLAGS)  $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
