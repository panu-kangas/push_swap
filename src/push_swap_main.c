/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:15:02 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 17:46:09 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_num_order(int *a, int *b, int *num_order)
{
	int	i;
	int	j;
	int	temp;

	num_order = malloc((a[0] + 1) * sizeof(int));
	if (num_order == NULL)
		error_exit(a, b, num_order);
	i = -1;
	while (++i <= a[0])
		num_order[i] = a[i];
	i = 0;
	while (++i < a[0])
	{
		j = 0;
		while (++j < a[0])
		{
			if (num_order[j] > num_order[j + 1])
			{
				temp = num_order[j];
				num_order[j] = num_order[j + 1];
				num_order[j + 1] = temp;
			}
		}
	}
	return (num_order);
}

void	set_stack_a_str(int num_count, char *argv, int *a)
{
	int		i;
	int		j;
	int		k;
	char	temp[12];

	a[0] = num_count;
	i = 0;
	k = 1;
	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i] != ' ' && argv[i] != '\0')
			temp[j++] = argv[i++];
		temp[j] = ' ';
		a[k++] = ft_atoi(temp);
		if (argv[i] == ' ')
			i++;
	}
}

void	set_stack_a(int num_count, char *argv[], int *a)
{
	int	i;
	int	j;

	a[0] = num_count;
	i = 1;
	j = 1;
	while (i <= num_count)
		a[i++] = ft_atoi(argv[j++]);
}

int	set_stacks(int *a, char *argv[], int argc, int num_count)
{
	if (argc == 2)
		set_stack_a_str(num_count, argv[1], a);
	else
		set_stack_a(num_count, argv, a);
	if (check_for_dup(a) == 1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	*num_order;
	int	num_count;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	num_order = NULL;
	num_count = check_input(argc, argv);
	if (num_count == -1)
		error_exit(a, b, num_order);
	a = malloc((num_count + 1) * sizeof(int));
	if (a == NULL)
		error_exit(a, b, num_order);
	if (set_stacks(a, argv, argc, num_count) == 1)
		error_exit(a, b, num_order);
	b = malloc((num_count + 1) * sizeof(int));
	if (b == NULL)
		error_exit(a, b, num_order);
	num_order = get_num_order(a, b, num_order);
	sort_stacks(a, b, num_order);
	free_all(a, b, num_order);
	return (0);
}
