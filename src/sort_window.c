/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:28 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:29 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	window_step(t_ctx *c, int *pushed, int w)
{
	int	r;

	r = stack_top(&c->a);
	if (r >= *pushed + w)
	{
		op_ra(c);
		return ;
	}
	op_pb(c);
	if (r < *pushed && c->b.size > 1)
		op_rb(c);
	(*pushed)++;
}

void	range_window_sort(t_ctx *c)
{
	int	*sorted;
	int	w;
	int	pushed;

	if (c->a.size < 2)
		return ;
	sorted = ranks_in(c);
	w = (int)ft_sqrt(c->a.size) * WINDOW_MUL / 10;
	if (w < 1)
		w = 1;
	pushed = 0;
	while (c->a.size > 0)
		window_step(c, &pushed, w);
	pull_back(c);
	ranks_out(&c->a, sorted);
}
