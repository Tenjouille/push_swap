NAME = push_swap
BONUS = checker
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
SRC_BONUS = get_next_line_utils.c \
			checker.c \
			algorithm_utils.c \
			instr_global.c \
			hit_number.c \
			list_manip_utils.c \
			list_manip.c \
			get_next_line.c \
			parsing.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g -fPIE

all: $(NAME)

$(NAME): $(OBJ)
	clang $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	clang $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS) 

re: fclean all

# malloc_test: $(OBJ) $(OBJ_BONUS)
# 	clang $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJ} ${OBJ_BONUS} -L.  -lmallocator

.PHONY: all clean fclean re bonus
