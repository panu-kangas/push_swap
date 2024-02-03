/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:37:19 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:55:40 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_position_in_b(int *a, int *b, int *num_order)
{
	int	i;

	if (check_biggest_smallest(a, b, 1) == 0 && num_order[0] <= 20)
		return (find_smallest(b));
	else if (check_biggest_smallest(a, b, 1) == 0 && num_order[0] > 20)
		return (find_i(a, b, num_order));
	if (a[1] < b[b[0]] && a[1] > b[1])
		return (0);
	i = 1;
	while (i < b[0])
	{
		if (a[1] < b[i] && a[1] > b[i + 1])
			break ;
		i++;
	}
	return (i);
}

void	sort_a_to_b(int *a, int *b, int *num_order)
{
	int	index;
	int	num;

	if (b[0] > 1)
	{
		index = check_position_in_b(a, b, num_order);
		if (index != 0)
		{
			num = b[index];
			while (b[b[0]] != num)
			{
				if (index >= (b[0] / 2))
					rrb(b);
				else
					rb(b);
			}
		}
	}
	pb(a, b);
}

void	sort_3(int *a, int *num_order)
{
	int	max_num;

	max_num = num_order[num_order[0]];
	if (max_num == a[1])
	{
		ra(a);
		if (a[1] > a[2])
			sa(a);
	}
	if (max_num == a[2])
	{
		rra(a);
		if (a[1] > a[2])
			sa(a);
	}
	if (max_num == a[3])
	{
		if (a[1] > a[2])
			sa(a);
	}
}

void	sort_small(int *a, int *b, int *num_order)
{
	while (a[0] > 3)
	{
		if (a[1] < num_order[num_order[0] - 2])
			sort_a_to_b(a, b, num_order);
		else
			ra(a);
	}
	sort_3(a, num_order);
	rotate_b(b);
	while (b[0] != 0 && num_order[0] <= 20)
		pa(a, b);
	while (a[0] != (num_order[0] % 8) && num_order[0] > 20)
		pa(a, b);
}

void	sort_stacks(int *a, int *b, int *num_order)
{
	if (a[0] == 1 || a[0] == 0 || check_is_sorted(a) == 1)
		return ;
	else if (a[0] == 2)
	{
		if (a[1] > a[2])
			sa(a);
	}
	else if (a[0] == 3)
		sort_3(a, num_order);
	else if (a[0] <= 20)
		sort_small(a, b, num_order);
	else if (a[0] <= 320)
		sort_mid(a, b, num_order);
	else
		sort_big(a, b, num_order);
}
