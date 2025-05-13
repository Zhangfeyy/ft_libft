SRCS = \
	src/ft_printf.c \
	src/ft_charstr.c \
	src/ft_deci.c \
	src/ft_hexa_pointer.c \
	src/ft_itoa_base.c 

OBJS = $(SRCS:src/%.c=$(BUILD_DIR)/%.o)
BUILD_DIR = build

CC = cc
AR = ar rcs
RM = rm -f

# -I to look for header files in the dic path passed via I
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilib/libft
NAME = libftprintf.a

# default target when you use "make"
all: libft $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

# create dictionaries as needed
$(BUILD_DIR):
	 mkdir -p $(BUILD_DIR)

# $< refers to the input file (the .c file)
# and $@ refers to the output file (the .o file).
# CREATE A BUILD dictionary if it doesnt exit by order only dependency pipeline

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) -C lib/libft fclean
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# -C to change the directory
libft:
	$(MAKE) -C lib/libft

# *************************** MAKEFILE DEBUGGING ***************************** #

print-%:
	echo -e $* = $($*)

.PHONY: all clean fclean re libft