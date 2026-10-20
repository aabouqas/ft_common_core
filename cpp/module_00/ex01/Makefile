# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 19:03:14 by aabouqas          #+#    #+#              #
#    Updated: 2024/08/23 16:27:00 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp utils.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = PhoneBook
all: $(NAME)

$(NAME): $(OBJ) PhoneBook.hpp Contact.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp PhoneBook.hpp Contact.hpp
	c++ $(CFLAGS) -c $<

re: clean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean
