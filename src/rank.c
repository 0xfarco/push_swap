/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:16 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 08:42:17 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*dup_ints(int *src, int n)
{
	int	*dup;
	int	i;

	dup = malloc(sizeof(int) * n);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

static void	sort_ints(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	rank_of(int *sorted, int n, int v)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n - 1;
	while (lo < hi)
	{
		mid = (lo + hi) / 2;
		if (sorted[mid] < v)
			lo = mid + 1;
		else
			hi = mid;
	}
	return (lo);
}

int	*ranks_in(t_ctx *c)
{
	int	*sorted;
	int	i;

	sorted = dup_ints(c->a.data, c->a.size);
	if (!sorted)
		fatal(c);
	sort_ints(sorted, c->a.size);
	i = 0;
	while (i < c->a.size)
	{
		c->a.data[i] = rank_of(sorted, c->a.size, c->a.data[i]);
		i++;
	}
	return (sorted);
}

void	ranks_out(t_stack *a, int *sorted)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		a->data[i] = sorted[a->data[i]];
		i++;
	}
	free(sorted);
}
