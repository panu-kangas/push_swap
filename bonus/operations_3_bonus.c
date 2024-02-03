/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:12:17 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 11:12:25 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
