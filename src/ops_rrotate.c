/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:00 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:01 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_ctx *c)
{
	stack_rrotate(&c->a);
	emit_op(c, OP_RRA);
}

void	op_rrb(t_ctx *c)
{
	stack_rrotate(&c->b);
	emit_op(c, OP_RRB);
}

void	op_rrr(t_ctx *c)
{
	stack_rrotate(&c->a);
	stack_rrotate(&c->b);
	emit_op(c, OP_RRR);
}
