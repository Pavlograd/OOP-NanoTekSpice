##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## create gcc Makefile
##

SRC			=	src/main.cpp			\
				src/Parsing.cpp			\
				src/Command.cpp			\
				src/Component.cpp		\
				src/C4001.cpp			\
				src/C4008.cpp			\
				src/C4011.cpp			\
				src/C4013.cpp			\
				src/C4017.cpp			\
				src/C4030.cpp			\
				src/C4069.cpp			\
				src/C4071.cpp			\
				src/C4081.cpp			\
				src/C4514.cpp			\
				src/C4040.cpp			\
				src/Clock.cpp			\
				src/Input.cpp			\
				src/Output.cpp			\
				src/True.cpp			\
				src/False.cpp			\

NAME		= nanotekspice

OBJ			= $(SRC:.cpp=.o)

XX			= g++

CXXFLAGS		= -Wall -Werror -Wextra

INCLUDE 	=	-I./include/

all		: $(NAME)

$(NAME)		: $(OBJ)
		$(XX) -o $(NAME) $(OBJ) $(INCLUDE)

clean		:
		rm -rf $(OBJ)

fclean		: clean
		rm -rf $(NAME)

re		: fclean all

debug		: $(CXXFLAGS) += -g

debug		: re

.cpp.o:
		$(XX) -c $< -o $@ $(INCLUDE) $(TEXT) $(GRAPH) $(DATA) $(CXXFLAGS)
