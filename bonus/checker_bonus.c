/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:21:31 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 11:08:12 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	num_count;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	num_count = check_input(argc, argv);
	if (num_count == -1)
		error_exit(a, b);
	a = malloc((num_count + 1) * sizeof(int));
	if (a == NULL)
		error_exit(a, b);
	if (set_stacks(a, argv, argc, num_count) == -1)
		error_exit(a, b);
	b = malloc((num_count + 1) * sizeof(int));
	if (b == NULL)
		error_exit(a, b);
	do_operations(a, b);
	free_all(a, b);
	return (0);
}
