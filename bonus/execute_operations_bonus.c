/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:52 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 16:59:27 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_for_r(int *a, int *b, char *str, int i)
{
	i++;
	if (str[i] == 'a' && str[i + 1] == '\n')
		ra(a);
	else if (str[i] == 'b' && str[i + 1] == '\n')
		rb(b);
	else if (str[i] == 'r' && str[i + 1] == '\n')
		rr(a, b);
	else if (str[i] == 'r' && str[i + 1] == 'a' && str[i + 2] == '\n')
		rra(a);
	else if (str[i] == 'r' && str[i + 1] == 'b' && str[i + 2] == '\n')
		rrb(b);
	else if (str[i] == 'r' && str[i + 1] == 'r' && str[i + 2] == '\n')
		rrr(a, b);
	else
		error_exit_operations(a, b, NULL, str);
}

void	check_for_p(int *a, int *b, char *str, int i)
{
	i++;
	if (str[i] == 'a' && str[i + 1] == '\n')
		pa(a, b);
	else if (str[i] == 'b' && str[i + 1] == '\n')
		pb(a, b);
	else
		error_exit_operations(a, b, NULL, str);
}

void	check_for_s(int *a, int *b, char *str, int i)
{
	i++;
	if (str[i] == 'a' && str[i + 1] == '\n')
		sa(a);
	else if (str[i] == 'b' && str[i + 1] == '\n')
		sb(b);
	else if (str[i] == 's' && str[i + 1] == '\n')
		ss(a, b);
	else
		error_exit_operations(a, b, NULL, str);
}

void	execute_operations(int *a, int *b, char *operations)
{
	int	i;

	i = 0;
	while (operations != NULL && operations[i] != '\0')
	{
		if (operations[i] == 's')
			check_for_s(a, b, operations, i);
		else if (operations[i] == 'p')
			check_for_p(a, b, operations, i);
		else if (operations[i] == 'r')
			check_for_r(a, b, operations, i);
		else
			error_exit_operations(a, b, NULL, operations);
		while (operations[i] != '\n')
			i++;
		i++;
	}
	if (check_is_sorted(a) == 1 && b[0] == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
