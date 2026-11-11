/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:22 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:23 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_pass(t_ctx *c, int bit)
{
	int	n;
	int	i;

	n = c->a.size;
	i = 0;
	while (i < n)
	{
		if ((stack_top(&c->a) >> bit) & 1)
			op_ra(c);
		else
			op_pb(c);
		i++;
	}
	while (c->b.size > 0)
		op_pa(c);
}

void	lsd_radix_sort(t_ctx *c)
{
	int	n;
	int	*sorted;
	int	bits;
	int	i;

	n = c->a.size;
	if (n < 2)
		return ;
	sorted = ranks_in(c);
	bits = 0;
	while (((n - 1) >> bits) != 0)
		bits++;
	i = 0;
	while (i < bits)
	{
		radix_pass(c, i);
		i++;
	}
	ranks_out(&c->a, sorted);
}
