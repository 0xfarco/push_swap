/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:10 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:11 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	read_digits(const char *s, size_t n)
{
	long	v;
	size_t	i;

	v = 0;
	i = 0;
	while (i < n)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		v = v * 10 + (s[i] - '0');
		if (v > 2147483648L)
			return (-1);
		i++;
	}
	return (v);
}

int	parse_int(const char *s, size_t len, int *out)
{
	long	v;
	int		sign;
	size_t	i;

	i = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (i == len)
		return (0);
	v = read_digits(s + i, len - i);
	if (v < 0)
		return (0);
	v *= sign;
	if (v > 2147483647L || v < -2147483648L)
		return (0);
	*out = (int)v;
	return (1);
}
