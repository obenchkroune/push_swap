CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Iinclude
NAME		=	push_swap

SRC_FILES	=	errrors.c main.c operations.c push.c rotate_a.c rotate_b.c sort.c swap.c utils.c

SRC			=	$(addprefix ./source/mandatory/, $(SRC_FILES))
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
