/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:03 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 17:12:06 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	op_sa(t_ctx *c)
{
	stack_swap(&c->a);
}

void	op_sb(t_ctx *c)
{
	stack_swap(&c->b);
}

void	op_ss(t_ctx *c)
{
	stack_swap(&c->a);
	stack_swap(&c->b);
}
