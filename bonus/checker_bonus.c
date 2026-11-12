/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:47:23 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/12 13:14:44 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line_bonus.h"

static void	print_result(t_ctx c, float disorder)
{
	if (disorder == 0.0 && c.b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_ctx	c;
	int		status;
	float	disorder;
	char	*op;

	status = parse_args(argc, argv, &c);
	if (status < 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (status == 0)
		return (0);
	op = get_next_line(0);
	while (op != NULL)
	{
		run_check(&c, op);
		free(op);
	}
	disorder = compute_disorder(&c.a);
	print_result(c, disorder);
	ctx_free(&c);
	return (0);
}
