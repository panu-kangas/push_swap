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

SRC = src/check_input.c src/operations_1.c src/operations_2.c src/operations_3.c src/push_swap_utils.c \
	src/push_swap_main.c src/sort_stacks.c src/sort_mid.c src/optimations.c src/sort_big.c \
	src/sort_b_to_a.c src/sort_block_of_100.c src/sort_remain_big.c src/sort_utils.c src/mid_big_utils.c

OBJ = $(SRC:.c=.o)

BSRC = bonus/checker_main_bonus.c bonus/input_bonus.c bonus/utils_bonus.c \
	   bonus/do_operations_bonus.c bonus/execute_operations_bonus.c \
	   bonus/operations_1_bonus.c bonus/operations_2_bonus.c bonus/operations_3_bonus.c

BOBJ = $(BSRC:.c=.o)

LIBFT = libft/libft.a

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BNAME) 
	
$(BNAME): $(BOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(BNAME)	

$(LIBFT):
	make all -C libft/.

clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)
	make clean -C libft/.

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	rm -f $(LIBFT)

re: fclean all
