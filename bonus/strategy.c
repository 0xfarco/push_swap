/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:41 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 14:30:37 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void run_check(t_ctx *c, const char *op) {
	int	id;

	id = op_id(op);
	
	if (id == OP_SA)
        op_sa(c);
    else if (id == OP_SB)
        op_sb(c);
    else if (id == OP_SS)
        op_ss(c);
    else if (id == OP_PA)
        op_pa(c);
    else if (id == OP_PB)
        op_pb(c);
    else if (id == OP_RA)
        op_ra(c);
    else if (id == OP_RB)
        op_rb(c);
    else if (id == OP_RR)
        op_rr(c);
    else if (id == OP_RRA)
        op_rra(c);
    else if (id == OP_RRB)
        op_rrb(c);
    else if (id == OP_RRR)
        op_rrr(c);
	else
		exit (1);
}