# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 20:16:58 by mapandel          #+#    #+#              #
#    Updated: 2017/04/02 17:33:28 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		alum1

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror -Weverything

#			Sources

SRC =		sources/main.c \
			sources/parsing_stdi.c \
			sources/display.c \
			sources/display2.c \
			sources/game.c \
			sources/parsing_param.c \

OBJ =		$(SRC:.c=.o)

INC =		includes

#			Library Path

LIBPATH =	libft/libft.a

#			Colors

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

#			Main Rules

.PHONY: all re glu clean fclean

$(NAME):
	@cd libft; $(MAKE) -f Makefile
	@echo "$(CYA)--::Compil Alum1::--$(DEF)"
	@make $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH)

all: $(NAME)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $^

#			Clean Rules

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Executable and Library Delection::--$(DEF)"
	@rm -rf $(NAME) $(LIBPATH)
