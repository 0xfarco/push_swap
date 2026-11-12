/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:48:34 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/12 12:50:50 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	str_eq(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

void	ft_putnbr_fd(size_t n, int fd)
{
	char	ch;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ch = '0' + n % 10;
	write(fd, &ch, 1);
}

float	compute_disorder(t_stack *s)
{
	int	i;
	int	j;
	int	mistakes;
	int	pairs;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			pairs++;
			if (s->data[i] < s->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (pairs == 0)
		return (0);
	return ((float)mistakes / pairs);
}
