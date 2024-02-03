/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:54:15 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 17:20:59 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_all(int *a, int *b)
{
	free(a);
	free(b);
}

void	error_exit(int *a, int *b)
{
	free(a);
	free(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_is_sorted(int *a)
{
	int	i;

	if (a[0] == 1)
		return (1);
	if (a[0] == 2)
	{
		if (a[1] < a[2])
			return (1);
	}
	if (a[1] > a[2])
		return (0);
	i = 2;
	while (i < a[0])
	{
		if (a[i - 1] > a[i])
			break ;
		if (a[i] > a[i + 1])
			break ;
		i++;
	}
	if (i == a[0])
		return (1);
	else
		return (0);
}

int	check_for_dup(int *a)
{
	int	i;
	int	j;

	i = 1;
	while (i <= a[0])
	{
		j = 1;
		while (j <= a[0])
		{
			if (a[i] == a[j] && i != j)
				return (1);
			j++;
			if (j > a[0])
				break ;
		}
		i++;
	}
	return (0);
}
