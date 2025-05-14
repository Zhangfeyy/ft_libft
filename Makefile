SRCS = \
	src/ft_printf.c \
	src/ft_charstr.c \
	src/ft_deci.c \
	src/ft_hexa_pointer.c \
	src/ft_itoa_base.c 

OBJ_DIR = build

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

CC = cc
AR = ar rcs
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilib/libft
NAME = libftprintf.a

all: libft $(NAME)

# Build the final static library, including libft object files
# Remove the libft.a
# ar command is used to manipulate archive files (like .a files, which are static libraries). 
# The x option extracts the contents (object files) of libft.a.
$(NAME): $(OBJS) | $(OBJ_DIR)
	cp lib/libft/libft.a $(OBJ_DIR)/libft.a
	cd $(OBJ_DIR) && ar x libft.a 
	$(AR) $@ $^ $(OBJ_DIR)/*.o

# Create build directories as needed
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile each source file into the build/obj directory
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C lib/libft fclean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libft:
	$(MAKE) -C lib/libft

.PHONY: all clean fclean re libft