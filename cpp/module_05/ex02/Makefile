# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 13:00:42 by aabouqas          #+#    #+#              #
#    Updated: 2024/10/15 17:02:25 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wextra -Werror -Wall -std=c++98
SRC = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ) Bureaucrat.hpp AForm.hpp
	c++  $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile
	c++ -c $(CFLAGS)  $<

clean:
	rm -f $(OBJ)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
