NAME    = push_swap
BONUS_NAME = checker

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I include

SRC_DIR = src
BONUS_SRC_DIR = bonus
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus-obj

SRCS    = main.c parse_args.c parse_int.c parse_utils.c \
          stack.c stack_ops.c stack_utils.c ctx.c utils.c \
          ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c ops_multi.c ops_emit.c \
          moves.c rank.c strategy.c bench.c \
          sort_simple.c sort_radix.c sort_window.c

BONUS_SRCS = checker.c ctx.c get_next_line.c get_next_line_utils.c ops_push.c \
		  ops_rotate.c ops_rrotate.c ops_swap.c parse_args.c parse_int.c \
		  parse_utils.c stack_ops.c stack.c strategy.c utils.c

OBJS    = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME) .bonus

.bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	touch .bonus

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_SRC_DIR)/checker.h
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) .bonus

re: fclean all

.PHONY: all bonus clean fclean re
