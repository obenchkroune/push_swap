CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude
NAME	=	push_swap

SRC		=	$(wildcard sources/*.c)
OBJ		=	$(patsubst sources/%.c, objects/%.o, $(SRC))

LIBFT	=	libft/libft.a

all: $(NAME)

objects/%.o: sources/%.c
	@mkdir -p objects
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft all

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	rm -rf objects

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
