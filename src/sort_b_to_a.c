/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:47:39 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 17:47:43 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_position_in_a(int *a, int *b, int *num_order, int x)
{
	int	i;

	if (check_biggest_smallest(b, a, x) == 0 && (a[0] + b[0]) <= 320)
		return (find_biggest(a));
	else if (check_biggest_smallest(b, a, x) == 0 && (a[0] + b[0]) > 320)
		return (find_i_block_of_100(a, b, num_order));
	if (b[x] > a[a[0]] && b[x] < a[1])
		return (0);
	i = 1;
	while (i < a[0])
	{
		if (b[x] > a[i] && b[x] < a[i + 1])
			return (i);
		i++;
	}
	return (i);
}

void	sort_b_to_a(int	*a, int *b, int *num_order)
{
	int	index;
	int	num;

	index = check_position_in_a(a, b, num_order, 1);
	if (index != 0)
	{
		num = a[index];
		while (a[a[0]] != num)
		{
			if (b[0] >= 2 && check_next_num(a, b, num_order) == 0)
			{
				sb(b);
				pa(a, b);
			}
			else
			{
				if (index >= (a[0] / 2))
					rra(a);
				else
					ra(a);
			}
		}
	}
	pa(a, b);
}
