/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:51:57 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/24 12:39:25 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num_len(char *argv, int i)
{
	int	len;

	len = 0;
	while (argv[i] != ' ' && argv[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int	check_valid_int(char *argv)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (ft_strlen(argv) > 11)
		return (-1);
	if (argv[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (argv[i] != '\0')
		num = num * 10 + argv[i++] - '0';
	num = num * sign;
	if (num < -2147483648 || num > 2147483647)
		return (-1);
	return (0);
}

int	check_valid_int_str(char *argv)
{
	long int	num;
	int			sign;
	int			i;

	i = 0;
	while (argv[i] != '\0')
	{
		num = 0;
		sign = 1;
		if (get_num_len(argv, i) > 11)
			return (-1);
		if (argv[i] == '-')
		{
			sign = -1;
			i++;
		}
		while (argv[i] != ' ' && argv[i] != '\0')
			num = num * 10 + argv[i++] - '0';
		num = num * sign;
		if (num < -2147483648 || num > 2147483647)
			return (-1);
		if (argv[i] == ' ')
			i++;
	}
	return (0);
}

int	is_string_valid(char *str, int num_count)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ' ')
		{
			if ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '-')
				num_count++;
			else
				return (-1);
		}
		else if (str[i] == '\0')
			return (num_count + 1);
		if (str[i] != ' ')
			return (-1);
		i++;
	}
	if (num_count == 0)
		return (-1);
	return (num_count);
}

int	check_input(int argc, char *argv[])
{
	int	i;
	int	num_count;

	num_count = 0;
	if (argc == 2)
	{
		if (is_string_valid(argv[1], num_count) == -1)
			return (-1);
		if (check_valid_int_str(argv[1]) == -1)
			return (-1);
		num_count = is_string_valid(argv[1], num_count);
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			if (is_string_valid(argv[i], num_count) != 1)
				return (-1);
			if (check_valid_int(argv[i++]) == -1)
				return (-1);
		}
		num_count = argc - 1;
	}
	return (num_count);
}
