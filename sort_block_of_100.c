/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_block_of_100.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:48:47 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 17:48:49 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_next_2(int *a, int block_size, int count, int *num_order)
{
	int	i;
	int	num;

	i = a[0];
	while (a[i] >= num_order[1] && a[i] <= num_order[num_order[0]])
		i--;
	while (1)
	{
		if (check_block_small(a[i], block_size, count, num_order) == 1)
			break ;
		if (check_block_big(a[i], block_size, count, num_order) == 1)
			break ;
		i++;
		if (i == a[0] + 1)
			i = 1;
	}
	num = a[i];
	rotate_to_num(a, num, i);
}

void	search_for_next(int *a, int block_size, int count, int *num_order)
{
	int	i;
	int	num;

	if (count == 2 || count == 4)
		search_next_2(a, block_size, count, num_order);
	else
	{
		i = 1;
		while (a[i + 1] >= num_order[1] && a[i + 1] <= num_order[num_order[0]])
			i++;
		while (1)
		{
			if (check_block_small(a[i], block_size, count, num_order) == 1)
				break ;
			if (check_block_big(a[i], block_size, count, num_order) == 1)
				break ;
			i--;
			if (i == 0)
				i = a[0];
		}
		num = a[i];
		rotate_to_num(a, num, i);
	}
}

void	divide_block_of_100(int *a, int *b, int *num_order, int block_size)
{
	int	count;
	int	i;

	count = 5;
	while (--count > 0)
	{
		i = 0;
		while (i < (block_size * 2))
		{
			search_for_next(a, block_size, count, num_order);
			if (check_block_small(a[1], block_size, count, num_order) == 1)
			{
				pb(a, b);
				rb(b);
				i++;
			}
			else if (check_block_big(a[1], block_size, count, num_order) == 1)
			{
				pb(a, b);
				i++;
			}
		}
	}
}

void	sort_block_of_100(int *a, int *b, int *num_order, int count)
{
	int	block_size;
	int	temp_order[101];
	int	remain;

	set_temp(temp_order, num_order, count);
	block_size = temp_order[0] / 8;
	divide_block_of_100(a, b, temp_order, block_size);
	while (a[a[0]] >= temp_order[1] && a[a[0]] <= temp_order[100])
		rra(a);
	remain = block_size % 8;
	while (b[0] < 100)
		sort_a_to_b(a, b, temp_order);
	rotate_b(b);
	while (remain-- > 0)
		pa(a, b);
	while (b[0] > 0)
		sort_b_to_a(a, b, temp_order);
}
