/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:44:39 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/03 08:54:12 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

int	push_char(t_line *l, char c)
{
	char	*tmp;

	if (l->len == l->cap)
	{
		tmp = malloc(l->cap * 2 + 1);
		if (!tmp)
			return (0);
		ft_memcpy(tmp, l->data, l->len);
		free(l->data);
		l->data = tmp;
		l->cap *= 2;
	}
	l->data[l->len++] = c;
	return (1);
}

char	*finish_line(t_line *l)
{
	if (l->len == 0)
	{
		free(l->data);
		return (NULL);
	}
	l->data[l->len] = '\0';
	return (l->data);
}
