/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:33:58 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 18:17:01 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_last_num(int *a, int *num_o, int block_size, int count)
{
	int	i;

	i = 0;
	while (i < 1 && count > 1)
	{
		if (check_block_small(a[a[0] - i], block_size, count, num_o) == 1)
		{
			while (i-- >= 0)
				rra(a);
			i = 0;
		}
		else if (check_block_big(a[a[0] - i], block_size, count, num_o) == 1)
		{
			while (i-- >= 0)
				rra(a);
			i = 0;
		}
		else
			i++;
	}
}

void	check_for_rr(int *a, int *b, int count, int *num_o)
{
	int	block_size;

	block_size = num_o[0] / 8;
	if (check_block_small(a[1], block_size, count, num_o) == 0 && b[0] != 1)
	{
		if (check_block_big(a[1], block_size, count, num_o) == 0)
			rr(a, b);
		else
			rb(b);
	}
	else
	{
		if (b[0] != 1)
			rb(b);
	}
}

void	check_for_rr_100(int *a, int *b, int count, int *num_o)
{
	int	block_size;

	block_size = 100;
	if (check_block_s_100(a[1], block_size, count, num_o) == 0 && b[0] != 1)
	{
		if (check_block_b_100(a[1], block_size, count, num_o) == 0)
			rr(a, b);
		else
			rb(b);
	}
	else
	{
		if (b[0] != 1)
			rb(b);
	}
}

void	check_last_num_100(int *a, int *num_o, int block_size, int count)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < 4 && count > 1)
	{
		if (check++ > a[0])
			break ;
		if (check_block_s_100(a[a[0] - i], block_size, count, num_o) == 1)
		{
			while (i-- >= 0)
				rra(a);
			i = 0;
		}
		else if (check_block_b_100(a[a[0] - i], block_size, count, num_o) == 1)
		{
			while (i-- >= 0)
				rra(a);
			i = 0;
		}
		else
			i++;
	}
}
