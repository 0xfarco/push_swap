/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:13 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:14 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	str_eq(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

int	flag_id(const char *arg)
{
	if (str_eq(arg, "--simple"))
		return (F_SIMPLE);
	if (str_eq(arg, "--medium"))
		return (F_MEDIUM);
	if (str_eq(arg, "--complex"))
		return (F_COMPLEX);
	if (str_eq(arg, "--adaptive"))
		return (F_ADAPTIVE);
	if (str_eq(arg, "--bench"))
		return (F_BENCH);
	return (F_NONE);
}

size_t	count_tokens(const char *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		n++;
		while (s[i] && !is_space(s[i]))
			i++;
	}
	return (n);
}
