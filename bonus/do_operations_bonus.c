/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:26 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 17:52:30 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_exit_operations(int *a, int *b, char *temp, char *operations)
{
	free(a);
	free(b);
	free(temp);
	free(operations);
	write(2, "Error\n", 6);
	exit(1);
}

char	*get_temp(char *temp, char *operations, char *buf, int bytes)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (operations == NULL)
		temp = malloc((bytes + 1) * sizeof(char));
	else
		temp = malloc((ft_strlen(operations) + bytes + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (operations != NULL && operations[j] != '\0')
		temp[i++] = operations[j++];
	free(operations);
	j = 0;
	while (j < bytes)
		temp[i++] = buf[j++];
	temp[i] = '\0';
	return (temp);
}

void	do_operations(int *a, int *b)
{
	char	buf[10];
	char	*temp;
	char	*operations;
	int		bytes;

	operations = NULL;
	while (1)
	{
		temp = NULL;
		bytes = read(0, buf, 10);
		if (bytes == -1 || bytes == 0)
			break ;
		temp = get_temp(temp, operations, buf, bytes);
		if (temp == NULL)
			error_exit_operations(a, b, temp, operations);
		operations = ft_strdup(temp);
		if (operations == NULL)
			error_exit_operations(a, b, temp, operations);
		free(temp);
	}
	if (bytes == -1)
		error_exit_operations(a, b, temp, operations);
	execute_operations(a, b, operations);
	free(operations);
}
