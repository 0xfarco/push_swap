#ifndef CHECKER_H
#define CHECKER_H

#include <stdlib.h>
#include <unistd.h>

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
	OP_ERROR
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
}	t_ctx;

/* stack.c / stack_ops.c / stack_utils.c */
int			stack_init(t_stack *s, int cap);
void		stack_push(t_stack *s, int v);
int			stack_pop(t_stack *s);
int			stack_top(t_stack *s);
void		stack_swap(t_stack *s);
void		stack_rotate(t_stack *s);
void		stack_rrotate(t_stack *s);
void		stack_reverse(t_stack *s);

void print_arr(t_stack s);

/* ctx.c */
void		ctx_init(t_ctx *c, int cap);
void		ctx_free(t_ctx *c);
void		fatal(t_ctx *c);

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

/* parsing */
int			is_space(char c);
size_t		count_tokens(const char *s);
int			parse_int(const char *s, size_t len, int *out);
int			parse_args(int argc, char **argv, t_ctx *c);

/* strategy.c / utils.c */
int			str_eq(const char *a, const char *b);
void		run_check(t_ctx *c, const char *op);
void		ft_putnbr_fd(size_t n, int fd);
void		ft_putstr_fd(const char *s, int fd);
float		compute_disorder(t_stack *s);

#endif