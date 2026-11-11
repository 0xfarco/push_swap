/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_multi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:52 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:41:53 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_ra(c);
}

void	rra_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_rra(c);
}

void	rb_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_rb(c);
}

void	rrb_n(t_ctx *c, int n)
{
	while (n-- > 0)
		op_rrb(c);
}
