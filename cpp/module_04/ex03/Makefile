# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 09:25:15 by aabouqas          #+#    #+#              #
#    Updated: 2024/10/04 10:59:00 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wextra -Werror -Wall -std=c++98 #-fsanitize=address -g
SRC = AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) main.cpp Makefile
	$(CC) $(CFLAGS) main.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp Makefile
	$(CC) $(CFLAGS) -c $<

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean
