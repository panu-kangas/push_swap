/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:10:43 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 11:12:07 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(int *a)
{
	int	temp;

	if (a[0] > 1)
	{
		temp = a[1];
		a[1] = a[2];
		a[2] = temp;
	}
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
}
