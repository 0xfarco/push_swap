/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:41:32 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 09:26:36 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef WINDOW_MUL
#  define WINDOW_MUL 20
# endif

# ifndef CHUNK_MUL
#  define CHUNK_MUL 25
# endif

# define LOW_DISORDER 0.2
# define MID_DISORDER 0.5

enum	e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
};

enum	e_strategy
{
	S_ADAPTIVE,
	S_SIMPLE,
	S_MEDIUM,
	S_COMPLEX
};

enum	e_flag
{
	F_NONE,
	F_SIMPLE,
	F_MEDIUM,
	F_COMPLEX,
	F_ADAPTIVE,
	F_BENCH
};

typedef struct s_stack
{
	int		*data;
	int		size;
}	t_stack;

typedef struct s_ctx
{
	t_stack	a;
	t_stack	b;
	size_t	cnt[OP_COUNT];
	int		pending;
}	t_ctx;

typedef struct s_opts
{
	int		strategy;
	int		bench;
}	t_opts;

/* stack.c / stack_ops.c / stack_utils.c */
int			stack_init(t_stack *s, int cap);
void		stack_push(t_stack *s, int v);
int			stack_pop(t_stack *s);
int			stack_top(t_stack *s);
void		stack_swap(t_stack *s);
void		stack_rotate(t_stack *s);
void		stack_rrotate(t_stack *s);
void		stack_reverse(t_stack *s);
int			min_index(t_stack *s);
int			max_index(t_stack *s);
float		compute_disorder(t_stack *s);

/* ctx.c */
void		ctx_init(t_ctx *c, int cap);
void		ctx_free(t_ctx *c);
void		fatal(t_ctx *c);
void		emit_op(t_ctx *c, int op);
void		flush_ops(t_ctx *c);

/* ops_*.c : the 11 push_swap instructions */
void		op_sa(t_ctx *c);
void		op_sb(t_ctx *c);
void		op_ss(t_ctx *c);
void		op_pa(t_ctx *c);
void		op_pb(t_ctx *c);
void		op_ra(t_ctx *c);
void		op_rb(t_ctx *c);
void		op_rr(t_ctx *c);
void		op_rra(t_ctx *c);
void		op_rrb(t_ctx *c);
void		op_rrr(t_ctx *c);

/* ops_multi.c / moves.c */
void		ra_n(t_ctx *c, int n);
void		rra_n(t_ctx *c, int n);
void		rb_n(t_ctx *c, int n);
void		rrb_n(t_ctx *c, int n);
void		a_to_top(t_ctx *c, int idx);
void		b_to_top(t_ctx *c, int idx);
void		pull_back(t_ctx *c);

/* rank.c */
int			rank_of(int *sorted, int n, int v);
int			*ranks_in(t_ctx *c);
void		ranks_out(t_stack *a, int *sorted);

/* sorting strategies */
void		selection_sort(t_ctx *c);
void		chunk_based_sort(t_ctx *c);
void		lsd_radix_sort(t_ctx *c);
void		range_window_sort(t_ctx *c);

/* parsing */
int			is_space(char c);
int			str_eq(const char *a, const char *b);
int			flag_id(const char *arg);
size_t		count_tokens(const char *s);
int			parse_int(const char *s, size_t len, int *out);
int			parse_args(int argc, char **argv, t_ctx *c, t_opts *o);

/* strategy.c / bench.c / utils.c */
const char	*strategy_name(int strategy, float disorder);
void		run_strategy(t_ctx *c, int strategy, float disorder);
void		bench_print(float disorder, const char *name, t_ctx *c);
double		ft_sqrt(double x);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putnbr_fd(size_t n, int fd);

#endif
