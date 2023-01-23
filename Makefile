NAME = push_swap
SRC = 	instructions.c \
		main.c \
		algorythme.c \
		algorythme_utils.c \
		list_manip.c \
		list_manip_utils.c \
		parsing.c \
		push_swap_utils.c \
		lil_algo.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS)  $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re