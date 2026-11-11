/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:00 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 17:12:04 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	op_rra(t_ctx *c)
{
	stack_rrotate(&c->a);
}

void	op_rrb(t_ctx *c)
{
	stack_rrotate(&c->b);
}

void	op_rrr(t_ctx *c)
{
	stack_rrotate(&c->a);
	stack_rrotate(&c->b);
}
