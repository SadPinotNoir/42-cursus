NAME = libft.a
SRC = $(shell find . -name "*.c" ! -name "*_bonus.c")
SRC_BONUS = $(shell find . -name "*_bonus.c")
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
COMPILE = gcc $(CFLAGS) -c
LIB = ar rc $(NAME)
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(OBJ)

%.o: %.c
	$(COMPILE) $< -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	$(LIB) $(OBJ_BONUS)

clean:
	$(REMOVE) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
