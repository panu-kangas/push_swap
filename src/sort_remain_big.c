/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_remain_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:29:54 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/26 17:51:57 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_temp_remain(int *temp, int *num_order, int remain)
{
	int	i;
	int	j;

	i = 1;
	j = ((num_order[0] / 200) * 200) + 1;
	temp[0] = remain;
	while (i <= remain)
		temp[i++] = num_order[j++];
}

void	sort_remain_big(int *a, int *b, int *num_order, int remain)
{
	int	block_size;
	int	temp_order[200];

	if (remain == 0)
		return ;
	set_temp_remain(temp_order, num_order, remain);
	block_size = temp_order[0] / 8;
	divide_block_of_100(a, b, temp_order, block_size);
	while (a[a[0]] >= temp_order[1] && a[a[0]] <= temp_order[temp_order[0]])
		rra(a);
	remain = temp_order[0] % 8;
	while (b[0] < temp_order[0])
		sort_a_to_b(a, b, temp_order);
	rotate_b(b);
	while (remain-- > 0)
		pa(a, b);
	while (b[0] > 0)
		sort_b_to_a(a, b, temp_order);
}
