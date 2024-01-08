CC			=	gcc
CFLAGS		=	-Werror -Iinclude
NAME		=	push_swap

SRC			=	./source/mandatory/performance.c ./source/mandatory/push_swap.c ./source/mandatory/sort.c ./source/mandatory/swap.c ./source/mandatory/utils.c ./source/mandatory/operations/moves.c ./source/mandatory/operations/push.c ./source/mandatory/operations/reverse_rotate.c ./source/mandatory/operations/rotate.c
OBJ			=	$(SRC:.c=.o)

LIBFT		=	libft/libft.a
LIBS		=	-Llibft -lft


all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft all

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBS)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
