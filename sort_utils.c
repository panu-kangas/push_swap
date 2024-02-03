/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:15:49 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:53:32 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(int *x)
{
	int	i;
	int	biggest;

	i = 1;
	biggest = x[1];
	while (i < x[0])
	{
		if (x[i + 1] > biggest)
			biggest = x[i + 1];
		i++;
	}
	i = 1;
	while (x[i] != biggest)
		i++;
	return (i);
}

int	find_smallest(int *x)
{
	int	i;
	int	smallest;

	i = 1;
	smallest = x[1];
	while (i < x[0])
	{
		if (x[i + 1] < smallest)
			smallest = x[i + 1];
		i++;
	}
	i = 1;
	while (x[i] != smallest)
		i++;
	return (i);
}

int	check_biggest_smallest(int *x, int *y, int pos)
{
	int	i;

	i = 0;
	while (++i <= y[0])
	{
		if (x[pos] > y[i])
			break ;
	}
	if (i == y[0] + 1)
		return (0);
	i = 0;
	while (++i <= y[0])
	{
		if (x[pos] < y[i])
			break ;
	}
	if (i == y[0] + 1)
		return (0);
	return (1);
}

void	rotate_a(int *a, int *num_order)
{
	int	i;
	int	num;

	i = 1;
	num = num_order[num_order[0]];
	while (a[i] != num)
		i++;
	while (a[a[0]] != num)
	{
		if (i >= (a[0] / 2))
			rra(a);
		else
			ra(a);
	}
}

void	rotate_b(int *b)
{
	int	index;
	int	num;

	index = find_biggest(b);
	num = b[index];
	while (b[1] != num)
	{
		if (index >= (b[0] / 2))
			rrb(b);
		else
			rb(b);
	}
}
