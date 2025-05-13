CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include -I./lib/libft
# link flag: lft
LIBS = -L./libftprintf -L./lib/libft -lft
NAME = test

SRC = test1.C
OBJ = $(SRC:.c=.o)

all: $(NAME) run

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY all clean fclean re run
