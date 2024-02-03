/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_big_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:14:33 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:47:22 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_i(int *a, int *b, int *num_order)
{
	int	i;
	int	min;
	int	max;

	i = 1;
	min = num_order[((num_order[0] / 8) * 8) + 1];
	max = num_order[num_order[0]];
	if (b[1] < min || b[1] > max)
		return (0);
	while (b[i] >= min && b[i] <= max)
		i++;
	if (a[1] < b[i - 1] && i != 1)
		return (i - 1);
	i--;
	while (b[i] >= min && b[i] <= max)
	{
		i--;
		if (i == 0)
			i = b[0];
	}
	return (i);
}

int	find_i_block_of_100(int *a, int *b, int *num_order)
{
	int	i;
	int	min;
	int	max;

	i = 1;
	min = num_order[1];
	max = num_order[num_order[0]];
	while (a[i] >= min && a[i] <= max)
		i++;
	if (b[1] > a[i - 1])
		return (i - 1);
	else
	{
		i--;
		while (a[i] >= min && a[i] <= max)
		{
			i--;
			if (i == 0)
				i = a[0];
		}
		return (i);
	}
}

int	check_next_num(int *a, int *b, int *num_order)
{
	if (check_position_in_a(a, b, num_order, 2) == 0)
		return (0);
	else if (check_position_in_a(a, b, num_order, 2) == a[0])
		return (0);
	else
		return (1);
}

void	rotate_to_num(int *a, int num, int i)
{
	while (a[1] != num)
	{
		if (i >= (a[0] / 2))
			rra(a);
		else
			ra(a);
	}
}

void	set_temp(int *temp, int *num_order, int count)
{
	int	i;
	int	j;

	i = 1;
	j = ((count - 1) * 100) + 1;
	temp[0] = 100;
	while (i < 101)
		temp[i++] = num_order[j++];
}
