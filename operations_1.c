/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:21:43 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:42:02 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a)
{
	int	temp;

	if (a[0] > 1)
	{
		temp = a[1];
		a[1] = a[2];
		a[2] = temp;
	}
	ft_printf("sa\n");
}

void	sb(int *b)
{
	int	temp;

	if (b[0] > 1)
	{
		temp = b[1];
		b[1] = b[2];
		b[2] = temp;
	}
	ft_printf("sb\n");
}

void	ss(int *a, int *b)
{
	int	temp;

	if (a[0] > 1)
	{
		temp = a[1];
		a[1] = a[2];
		a[2] = temp;
	}
	if (b[0] > 1)
	{
		temp = b[1];
		b[1] = b[2];
		b[2] = temp;
	}
	ft_printf("ss\n");
}
