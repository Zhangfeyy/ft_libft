SRCS = \
	src/ft_printf.c \
	src/ft_charstr.c \
	src/ft_deci.c \
	src/ft_hexa_pointer.c \
	src/ft_itoa_base.c 

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TMP_DIR = $(BUILD_DIR)/tmp

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

CC = cc
AR = ar rcs
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilib/libft
NAME = libftprintf.a

# Default target
all: libft $(NAME)

# Build the final static library, including libft object files
$(NAME): $(OBJS) | $(TMP_DIR)
	cp lib/libft/libft.a $(TMP_DIR)/libft.a
	cd $(TMP_DIR) && ar x libft.a
	$(AR) $@ $^ $(TMP_DIR)/*.o

# Create build directories as needed
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TMP_DIR):
	mkdir -p $(TMP_DIR)

# Compile each source file into the build/obj directory
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C lib/libft fclean
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libft:
	$(MAKE) -C lib/libft

.PHONY: all clean fclean re libft