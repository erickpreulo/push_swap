# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 12:30:51 by egomes            #+#    #+#              #
#    Updated: 2021/08/04 18:30:20 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c src.c

NAME = push_swap

INCLUD = -I .

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

.c.o:
			@$(CC)  $(CFLAGS) $(INCLUD) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			
all:		$(NAME)

test:	re
		@$(CC) $(CFLAGS) test.c $(NAME) -fsanitize=address -g

clean:
		${shell find . -type f -name "*.o" -delete}
##		${wildcard */*.o}
##	rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
