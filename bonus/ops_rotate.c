/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:58 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 14:27:57 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	op_ra(t_ctx *c)
{
	stack_rotate(&c->a);
}

void	op_rb(t_ctx *c)
{
	stack_rotate(&c->b);
}

void	op_rr(t_ctx *c)
{
	stack_rotate(&c->a);
	stack_rotate(&c->b);
}
