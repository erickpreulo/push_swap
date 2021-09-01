# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 12:30:51 by egomes            #+#    #+#              #
#    Updated: 2021/09/01 04:22:55 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c src/src.c src/validation.c src/print.c src/v_command.c commands/pa.c commands/pb.c commands/ra_rb_rr.c commands/rra_rrb_rrr.c commands/sa_sb_ss.c order_functions/order_else.c order_functions/order_5.c order_functions/src_order.c order_functions/order_verify.c

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
