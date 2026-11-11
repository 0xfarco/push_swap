/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:35 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:49:51 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_stat(const char *label, size_t value, ...)
{
	va_list	args;

	va_start(args, value);
	while (label)
	{
		ft_putstr_fd((char *)label, 2);
		ft_putnbr_fd(value, 2);
		label = va_arg(args, const char *);
		if (label)
			value = va_arg(args, size_t);
	}
	ft_putstr_fd("\n", 2);
	va_end(args);
}

static size_t	total_ops(t_ctx *c)
{
	size_t	total;
	int		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += c->cnt[i];
		i++;
	}
	return (total);
}

static void	bench_disorder(float disorder, const char *name)
{
	int	pct;

	pct = (int)(disorder * 10000 + 0.5f);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(pct / 100, 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd((pct / 10) % 10, 2);
	ft_putnbr_fd(pct % 10, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
}

void	bench_print(float disorder, const char *name, t_ctx *c)
{
	bench_disorder(disorder, name);
	put_stat("[bench] total_ops: ", total_ops(c), NULL);
	put_stat("[bench] sa: ", c->cnt[OP_SA],
		" sb: ", c->cnt[OP_SB], " ss: ", c->cnt[OP_SS],
		" pa: ", c->cnt[OP_PA], " pb: ", c->cnt[OP_PB], NULL);
	put_stat("[bench] ra: ", c->cnt[OP_RA], " rb: ", c->cnt[OP_RB],
		" rr: ", c->cnt[OP_RR], " rra: ", c->cnt[OP_RRA],
		" rrb: ", c->cnt[OP_RRB], " rrr: ", c->cnt[OP_RRR], NULL);
}
