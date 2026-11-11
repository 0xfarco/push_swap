/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:58 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:41:59 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_ctx *c)
{
	stack_rotate(&c->a);
	emit_op(c, OP_RA);
}

void	op_rb(t_ctx *c)
{
	stack_rotate(&c->b);
	emit_op(c, OP_RB);
}

void	op_rr(t_ctx *c)
{
	stack_rotate(&c->a);
	stack_rotate(&c->b);
	emit_op(c, OP_RR);
}
