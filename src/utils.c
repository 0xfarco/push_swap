/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:46 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:47 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_sqrt(double x)
{
	double	y;
	int		p;
	int		c;

	p = 1;
	while (x > (p + 1) * (p + 1))
		p++;
	y = (double)p;
	c = 0;
	while (c < 10)
	{
		y = (x / y + y) / 2;
		if (y * y == x)
			return (y);
		c++;
	}
	return (y);
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
