#include "checker.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_ctx	c;
	int		status;
	float	disorder;
	char 	*op;

	status = parse_args(argc, argv, &c);
	if (status < 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (status == 0)
		return (0);

	while ((op = get_next_line(0)) != NULL) {
		run_check(&c, op);
		free(op);
	}

	disorder = compute_disorder(&c.a);
	if (disorder == 0.0 && c.b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);

	ctx_free(&c);
	return (0);
}