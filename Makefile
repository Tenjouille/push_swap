NAME = push_swap
SRC = 	instr_global.c \
		instr_push_n_swap.c \
		instr_rotates.c \
		main.c \
		algorithm.c \
		algorithm_utils.c \
		list_manip.c \
		list_manip_utils.c \
		parsing.c \
		push_swap_utils.c \
		lil_algo.c \
		hit_number.c \
		cmd_manip.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS)  $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re