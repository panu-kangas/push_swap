/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:15:52 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:45:06 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	pa(int *a, int *b);
void	pb(int *a, int *b);
void	ra(int *a);
void	rb(int *b);
void	rr(int *a, int *b);
void	rra(int *a);
void	rrb(int *b);
void	rrr(int *a, int *b);
void	free_all(int *a, int *b, int *num_order);
void	error_exit(int *a, int *b, int *num_order);
int		check_input(int argc, char *argv[]);
int		check_for_dup(int *a);
int		check_is_sorted(int *a);
void	sort_stacks(int *a, int *b, int *num_order);
int		check_biggest_smallest(int *x, int *y, int pos);
void	sort_mid(int *a, int *b, int *num_order);
void	check_last_num(int *a, int *num_order, int block_size, int count);
void	check_last_num_100(int *a, int *num_order, int block_size, int count);
void	check_for_rr(int *a, int *b, int count, int *num_order);
void	check_for_rr_100(int *a, int *b, int count, int *num_order);
int		find_i(int *x, int *y, int *num_order);
int		find_i_block_of_100(int *a, int *b, int *num_order);
void	sort_a_to_b(int *a, int *b, int *num_order);
void	sort_b_to_a(int	*a, int *b, int *num_order);
int		check_next_num(int *a, int *b, int *num_order);
int		check_position_in_a(int *a, int *b, int *num_order, int x);
int		find_smallest(int *x);
int		find_biggest(int *x);
void	rotate_a(int *a, int *num_order);
void	rotate_b(int *b);
void	sort_small(int *a, int *b, int *num_order);
int		check_block_small(int num, int block_size, int count, int *num_order);
int		check_block_s_100(int num, int block_size, int count, int *num_order);
int		check_block_big(int num, int block_size, int count, int *num_order);
int		check_block_b_100(int num, int block_size, int count, int *num_order);
void	sort_big(int *a, int *b, int *num_order);
void	sort_block_of_100(int *a, int *b, int *num_order, int count);
void	rotate_to_num(int *a, int num, int i);
void	set_temp(int *temp, int *num_order, int count);
void	sort_remain_big(int *a, int *b, int *num_order, int remain);
void	divide_100(int *a, int *b, int *num_order, int block_size);

#endif
