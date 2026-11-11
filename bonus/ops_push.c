/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:55 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 14:27:46 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	op_pa(t_ctx *c)
{
	if (c->b.size == 0)
		return ;
	stack_push(&c->a, stack_pop(&c->b));
}

void	op_pb(t_ctx *c)
{
	if (c->a.size == 0)
		return ;
	stack_push(&c->b, stack_pop(&c->a));
}
