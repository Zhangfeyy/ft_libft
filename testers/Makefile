SRCS = \
	src/test1.c
OBJS_DIR = build
OBJS = $(SRCS:src/*.c = $(OBJS_DIR)/*.o)

LIBS = ../libftprinft.a

NAME = test
CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I $(INCLUDES))
# makefile cannot direcctly operate all the directories
# so we can only use shell command to search for all the dirs
INCLUDES = $(shell find .. -type d)
# link flag: lft

all: $(LIBS) $(NAME) run

$(LIBS):
	$(MAKE) -C $(LIBS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY all clean fclean re run
