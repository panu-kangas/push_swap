/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:50:08 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:53:54 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *a, int *b)
{
	int	i;

	i = a[0];
	if (b[0] > 0)
	{
		while (i > 0)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[1] = b[1];
		a[0] = a[0] + 1;
		b[0] = b[0] - 1;
		i = 1;
		while (i <= b[0])
		{
			b[i] = b[i + 1];
			i++;
		}
		b[i] = 0;
	}
	ft_printf("pa\n");
}

void	pb(int *a, int *b)
{
	int	i;

	i = b[0];
	if (a[0] > 0)
	{
		while (i > 0)
		{
			b[i + 1] = b[i];
			i--;
		}
		b[1] = a[1];
		b[0] = b[0] + 1;
		a[0] = a[0] - 1;
		i = 1;
		while (i <= a[0])
		{
			a[i] = a[i + 1];
			i++;
		}
		a[i] = 0;
	}
	ft_printf("pb\n");
}

void	ra(int *a)
{
	int	i;
	int	temp;

	if (a[0] > 1)
	{
		temp = a[1];
		i = 1;
		while (i < a[0])
		{
			a[i] = a[i + 1];
			i++;
		}
		a[i] = temp;
	}
	ft_printf("ra\n");
}

void	rb(int *b)
{
	int	i;
	int	temp;

	if (b[0] > 1)
	{
		temp = b[1];
		i = 1;
		while (i < b[0])
		{
			b[i] = b[i + 1];
			i++;
		}
		b[i] = temp;
	}
	ft_printf("rb\n");
}

void	rr(int *a, int *b)
{
	int	i;
	int	temp;

	if (a[0] > 1)
	{
		temp = a[1];
		i = 0;
		while (++i < a[0])
			a[i] = a[i + 1];
		a[i] = temp;
	}
	if (b[0] > 1)
	{
		temp = b[1];
		i = 0;
		while (++i < b[0])
			b[i] = b[i + 1];
		b[i] = temp;
	}
	ft_printf("rr\n");
}
