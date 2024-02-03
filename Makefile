# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 10:35:32 by pkangas           #+#    #+#              #
#    Updated: 2024/01/30 11:13:53 by pkangas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = check_input.c operations_1.c operations_2.c operations_3.c push_swap_utils.c \
	  push_swap.c sort_stacks.c sort_mid.c optimations.c sort_big.c \
	  sort_b_to_a.c sort_block_of_100.c sort_remain_big.c sort_utils.c mid_big_utils.c

OBJ = $(SRC:.c=.o)

BSRC = bonus/checker_bonus.c bonus/input_bonus.c bonus/utils_bonus.c \
	   bonus/do_operations_bonus.c bonus/execute_operations_bonus.c \
	   bonus/operations_1_bonus.c bonus/operations_2_bonus.c bonus/operations_3_bonus.c

BOBJ = $(BSRC:.c=.o)

LIBFT = ./libft/libft.a

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BNAME) 
	
$(BNAME): $(BOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(BNAME)	

$(LIBFT):
	make all -C ./libft/.

clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)
	make clean -C ./libft/.

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	rm -f $(LIBFT)

re: fclean all
