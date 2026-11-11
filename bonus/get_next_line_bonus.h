/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:44:33 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/03 08:54:16 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define LINE_CAP 64

typedef struct s_state
{
	char	*buf;
	char	*ptr;
	ssize_t	left;
}	t_state;

typedef struct s_line
{
	char	*data;
	size_t	len;
	size_t	cap;
}	t_line;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		push_char(t_line *l, char c);
char	*finish_line(t_line *l);

#endif
