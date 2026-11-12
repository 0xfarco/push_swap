/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:47:45 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/12 13:11:42 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	reset(t_state *st)
{
	free(st->buf);
	st->buf = NULL;
	st->ptr = NULL;
	st->left = 0;
}

static char	*fail(t_state *st, t_line *l)
{
	free(l->data);
	reset(st);
	return (NULL);
}

static int	init_line(t_line *l)
{
	l->cap = LINE_CAP;
	l->len = 0;
	l->data = malloc(l->cap + 1);
	return (l->data != NULL);
}

static int	fill(t_state *st, int fd)
{
	ssize_t	n;

	if (st->left > 0)
		return (1);
	if (!st->buf)
		st->buf = malloc(BUFFER_SIZE);
	if (!st->buf)
		return (-1);
	n = read(fd, st->buf, BUFFER_SIZE);
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	st->left = n;
	st->ptr = st->buf;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_state	st;
	t_line			l;
	int				ready;
	char			c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!init_line(&l))
		return (NULL);
	while (1)
	{
		ready = fill(&st, fd);
		if (ready < 0)
			return (fail(&st, &l));
		if (ready == 0)
			return (reset(&st), finish_line(&l));
		c = *st.ptr++;
		st.left--;
		if (c != '\n' && !push_char(&l, c))
			return (fail(&st, &l));
		if (c == '\n')
			return (finish_line(&l));
	}
}
