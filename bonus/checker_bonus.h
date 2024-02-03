/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkangas <pkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:14:03 by pkangas           #+#    #+#             */
/*   Updated: 2024/01/29 17:51:54 by pkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	pa(int *a, int *b);
void	pb(int *a, int *b);
void	ra(int *a);
void	rb(int *b);
void	rr(int *a, int *b);
void	rra(int *a);
void	rrb(int *b);
void	rrr(int *a, int *b);
int		check_input(int argc, char *argv[]);
void	error_exit(int *a, int *b);
void	free_all(int *a, int *b);
int		check_for_dup(int *a);
void	do_operations(int *a, int *b);
void	execute_operations(int *a, int *b, char *operations);
void	error_exit_operations(int *a, int *b, char *temp, char *operations);
int		check_is_sorted(int *a);

#endif
