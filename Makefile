CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Iinc
NAME		=	push_swap

SRC			=	$(shell find ./src -type f -name *.c)
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
