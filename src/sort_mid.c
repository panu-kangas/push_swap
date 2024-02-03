/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:51:28 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:51:35 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_block_big(int num, int block_size, int count, int *num_order)
{
	int	start;
	int	end;

	start = num_order[block_size * 4];
	end = num_order[block_size * (9 - count)];
	if (num > start && num <= end)
		return (1);
	else
		return (0);
}

int	check_block_small(int num, int block_size, int count, int *num_order)
{
	int	start;
	int	end;

	if (count == 1)
		start = num_order[1];
	else
		start = num_order[block_size * (count - 1)];
	end = num_order[block_size * 4];
	if (count == 1)
	{
		if (num >= start && num <= end)
			return (1);
	}
	else
	{
		if (num > start && num <= end)
			return (1);
	}
	return (0);
}

void	divide_to_blocks(int *a, int *b, int *num_order, int block_size)
{
	int	count;
	int	i;

	count = 5;
	while (--count > 0)
	{
		i = 0;
		check_last_num(a, num_order, block_size, count);
		while (i < (block_size * 2))
		{
			if (check_block_small(a[1], block_size, count, num_order) == 1)
			{
				pb(a, b);
				check_for_rr(a, b, count, num_order);
				i++;
			}
			else if (check_block_big(a[1], block_size, count, num_order) == 1)
			{
				pb(a, b);
				i++;
			}
			else
				ra(a);
		}
	}
}

void	sort_mid(int *a, int *b, int *num_order)
{
	int	block_size;

	block_size = num_order[0] / 8;
	divide_to_blocks(a, b, num_order, block_size);
	sort_small(a, b, num_order);
	while (b[0] > 0)
		sort_b_to_a(a, b, num_order);
	rotate_a(a, num_order);
}
