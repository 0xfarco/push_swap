/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:31 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/12 12:48:28 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	stack_swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->data[s->size - 1];
	s->data[s->size - 1] = s->data[s->size - 2];
	s->data[s->size - 2] = tmp;
}

void	stack_rotate(t_stack *s)
{
	int	first;
	int	i;

	if (s->size < 2)
		return ;
	first = s->data[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = first;
}

void	stack_rrotate(t_stack *s)
{
	int	last;
	int	i;

	if (s->size < 2)
		return ;
	last = s->data[0];
	i = 0;
	while (i + 1 < s->size)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->size - 1] = last;
}

void	stack_reverse(t_stack *s)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < s->size / 2)
	{
		tmp = s->data[i];
		s->data[i] = s->data[s->size - 1 - i];
		s->data[s->size - 1 - i] = tmp;
		i++;
	}
}
