/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:48:16 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 17:48:19 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_block_b_100(int num, int block_size, int count, int *num_order)
{
	int	start;
	int	end;
	int	half;

	half = num_order[0] / 200;
	start = num_order[block_size * half];
	end = num_order[block_size * ((half * 2) - count + 1)];
	if (num > start && num <= end)
		return (1);
	else
		return (0);
}

int	check_block_s_100(int num, int block_size, int count, int *num_order)
{
	int	start;
	int	end;

	if (count == 1)
		start = num_order[1];
	else
		start = num_order[block_size * (count - 1)];
	end = num_order[block_size * (num_order[0] / 200)];
	if (count != 1)
	{
		if (num > start && num <= end)
			return (1);
		else
			return (0);
	}
	else
	{
		if (num >= start && num <= end)
			return (1);
		else
			return (0);
	}
}

void	divide_to_blocks_100(int *a, int *b, int *num_order, int block_size)
{
	int	count;
	int	i;

	count = (num_order[0] / 200) + 1;
	while (--count > 0)
	{
		i = 0;
		check_last_num_100(a, num_order, block_size, count);
		while (i < (block_size * 2))
		{
			if (check_block_s_100(a[1], block_size, count, num_order) == 1)
			{
				pb(a, b);
				check_for_rr_100(a, b, count, num_order);
				i++;
			}
			else if (check_block_b_100(a[1], block_size, count, num_order) == 1)
			{
				pb(a, b);
				i++;
			}
			else
				ra(a);
		}
	}
}

void	sort_big(int *a, int *b, int *num_order)
{
	int	block_size;
	int	block_count;
	int	count;
	int	remain;

	block_size = 100;
	divide_to_blocks_100(a, b, num_order, block_size);
	remain = a[0];
	while (b[0] > 0)
		pa(a, b);
	block_count = (num_order[0] / 200) * 2;
	count = 1;
	while (block_count > 0)
	{
		sort_block_of_100(a, b, num_order, count);
		while (a[1] <= num_order[100 * count] && a[1] != num_order[1])
			ra(a);
		block_count--;
		count++;
	}
	sort_remain_big(a, b, num_order, remain);
	rotate_a(a, num_order);
}
