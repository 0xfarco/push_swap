/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_emit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:49 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:41:50 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*op_name(int op)
{
	static const char	*names[OP_COUNT] = {"sa\n", "sb\n", "ss\n", "pa\n",
		"pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	return (names[op]);
}

static int	pair_of(int x, int y)
{
	if ((x == OP_RA && y == OP_RB) || (x == OP_RB && y == OP_RA))
		return (OP_RR);
	if ((x == OP_RRA && y == OP_RRB) || (x == OP_RRB && y == OP_RRA))
		return (OP_RRR);
	if ((x == OP_SA && y == OP_SB) || (x == OP_SB && y == OP_SA))
		return (OP_SS);
	return (-1);
}

static void	write_op(t_ctx *c, int op)
{
	const char	*name;
	size_t		len;

	name = op_name(op);
	len = 0;
	while (name[len])
		len++;
	write(1, name, len);
	c->cnt[op]++;
}

void	flush_ops(t_ctx *c)
{
	if (c->pending >= 0)
		write_op(c, c->pending);
	c->pending = -1;
}

void	emit_op(t_ctx *c, int op)
{
	int	merged;

	merged = -1;
	if (c->pending >= 0)
		merged = pair_of(c->pending, op);
	if (merged >= 0)
	{
		write_op(c, merged);
		c->pending = -1;
		return ;
	}
	flush_ops(c);
	if (op == OP_RA || op == OP_RB || op == OP_RRA || op == OP_RRB
		|| op == OP_SA || op == OP_SB)
		c->pending = op;
	else
		write_op(c, op);
}
