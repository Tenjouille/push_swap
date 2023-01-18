NAME = push_swap
SRC = 	instructions.c \
		main.c \
		algorythme.c \
		algorythme_utils.c \
		list_manip.c \
		list_manip_utils.c \
		parsing.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) push_swap.h
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re