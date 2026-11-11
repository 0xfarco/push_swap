/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:07 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:08 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_dup(t_stack *list, int v)
{
	int	i;

	i = 0;
	while (i < list->size)
	{
		if (list->data[i] == v)
			return (1);
		i++;
	}
	return (0);
}

static int	add_numbers(const char *s, t_stack *list)
{
	size_t	i;
	size_t	start;
	int		v;
	int		found;

	i = 0;
	found = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && !is_space(s[i]))
			i++;
		if (!parse_int(s + start, i - start, &v) || has_dup(list, v))
			return (0);
		stack_push(list, v);
		found = 1;
	}
	return (found);
}

static long	scan_args(int argc, char **argv, t_opts *o)
{
	long	total;
	int		i;
	int		id;

	total = 0;
	i = 1;
	while (i < argc)
	{
		id = flag_id(argv[i]);
		if (id == F_SIMPLE || id == F_MEDIUM || id == F_COMPLEX)
			o->strategy = id;
		else if (id == F_ADAPTIVE)
			o->strategy = S_ADAPTIVE;
		else if (id == F_BENCH)
			o->bench = 1;
		else if (count_tokens(argv[i]) == 0)
			return (-1);
		else
			total += (long)count_tokens(argv[i]);
		i++;
	}
	return (total);
}

static int	fill_stack(int argc, char **argv, t_stack *list)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!flag_id(argv[i]) && !add_numbers(argv[i], list))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_ctx *c, t_opts *o)
{
	long	total;

	o->strategy = S_ADAPTIVE;
	o->bench = 0;
	total = scan_args(argc, argv, o);
	if (total < 0)
		return (-1);
	if (total == 0)
		return (0);
	ctx_init(c, (int)total);
	if (!fill_stack(argc, argv, &c->a))
	{
		ctx_free(c);
		return (-1);
	}
	stack_reverse(&c->a);
	return (1);
}
