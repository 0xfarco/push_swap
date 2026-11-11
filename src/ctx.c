/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:39 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:41:40 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ctx_free(t_ctx *c)
{
	free(c->a.data);
	free(c->b.data);
	c->a.data = NULL;
	c->b.data = NULL;
}

void	fatal(t_ctx *c)
{
	ctx_free(c);
	write(2, "Error\n", 6);
	exit(1);
}

void	ctx_init(t_ctx *c, int cap)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
	{
		c->cnt[i] = 0;
		i++;
	}
	c->pending = -1;
	c->a.data = NULL;
	c->b.data = NULL;
	if (!stack_init(&c->a, cap) || !stack_init(&c->b, cap))
		fatal(c);
}
