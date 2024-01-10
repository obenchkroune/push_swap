CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Iinc
NAME		=	push_swap

SRC			=	./src/errors.c ./src/sort.c ./src/sorting/rotate_push_a.c ./src/sorting/costs/get_ra_rb_cost.c ./src/sorting/costs/get_rra_rrb_cost.c ./src/sorting/costs/get_ra_cost.c ./src/sorting/costs/get_ra_rrb.c ./src/sorting/costs/get_rra_cost.c ./src/sorting/check_median_push_b.c ./src/sorting/rotations/do_rra.c ./src/sorting/rotations/do_ra_rb.c ./src/sorting/rotations/do_ra_rrb.c ./src/sorting/rotations/do_ra.c ./src/sorting/rotations/do_rra_rrb.c ./src/sorting/check_position.c ./src/instructions/rotate.c ./src/instructions/swap.c ./src/instructions/reverse_rotate.c ./src/instructions/push.c ./src/instructions/helpers.c ./src/utils/cost_utils.c ./src/utils/error_handlers.c ./src/utils/sort_utils.c ./src/utils/init_stacks.c ./src/utils/cleanup.c ./src/helpers.c ./src/main.c
OBJ			=	$(SRC:.c=.o)

LIBFT		=	libft/libft.a
LIBS		=	-Llibft -lft

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft all

$(NAME): $(OBJ) $(LIBFT) ./inc/push_swap.h
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBS)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
