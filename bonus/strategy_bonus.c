/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:41 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/12 13:08:35 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	op_id(const char *op)
{
	if (str_eq(op, "sa"))
		return (OP_SA);
	if (str_eq(op, "sb"))
		return (OP_SB);
	if (str_eq(op, "ss"))
		return (OP_SS);
	if (str_eq(op, "pa"))
		return (OP_PA);
	if (str_eq(op, "pb"))
		return (OP_PB);
	if (str_eq(op, "ra"))
		return (OP_RA);
	if (str_eq(op, "rb"))
		return (OP_RB);
	if (str_eq(op, "rr"))
		return (OP_RR);
	if (str_eq(op, "rra"))
		return (OP_RRA);
	if (str_eq(op, "rrb"))
		return (OP_RRB);
	if (str_eq(op, "rrr"))
		return (OP_RRR);
	return (OP_ERROR);
}

static int	scan_ops(const char *op)
{
	int		id;

	id = op_id(op);
	return (id);
}

void	run_check(t_ctx *c, const char *op)
{
	if (scan_ops(op) == OP_SA)
		op_sa(c);
	else if (scan_ops(op) == OP_SB)
		op_sb(c);
	else if (scan_ops(op) == OP_SS)
		op_ss(c);
	else if (scan_ops(op) == OP_PA)
		op_pa(c);
	else if (scan_ops(op) == OP_PB)
		op_pb(c);
	else if (scan_ops(op) == OP_RA)
		op_ra(c);
	else if (scan_ops(op) == OP_RB)
		op_rb(c);
	else if (scan_ops(op) == OP_RR)
		op_rr(c);
	else if (scan_ops(op) == OP_RRA)
		op_rra(c);
	else if (scan_ops(op) == OP_RRB)
		op_rrb(c);
	else if (scan_ops(op) == OP_RRR)
		op_rrr(c);
	else
		exit (1);
}
