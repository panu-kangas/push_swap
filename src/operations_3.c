/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:49:59 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:46:27 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *a)
{
	int	i;
	int	temp;

	if (a[0] > 1)
	{
		i = a[0];
		temp = a[i];
		while (i > 1)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[1] = temp;
	}
	ft_printf("rra\n");
}

void	rrb(int *b)
{
	int	i;
	int	temp;

	if (b[0] > 1)
	{
		i = b[0];
		temp = b[i];
		while (i > 1)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[1] = temp;
	}
	ft_printf("rrb\n");
}

void	rrr(int *a, int *b)
{
	int	i;
	int	temp;

	if (a[0] > 1)
	{
		i = a[0];
		temp = a[i];
		i++;
		while (--i > 1)
			a[i] = a[i - 1];
		a[1] = temp;
	}
	if (b[0] > 1)
	{
		i = b[0];
		temp = b[i];
		i++;
		while (--i > 1)
			b[i] = b[i - 1];
		b[1] = temp;
	}
	ft_printf("rrr\n");
}
