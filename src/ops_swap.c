/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:03 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:04 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_ctx *c)
{
	stack_swap(&c->a);
	emit_op(c, OP_SA);
}

void	op_sb(t_ctx *c)
{
	stack_swap(&c->b);
	emit_op(c, OP_SB);
}

void	op_ss(t_ctx *c)
{
	stack_swap(&c->a);
	stack_swap(&c->b);
	emit_op(c, OP_SS);
}
