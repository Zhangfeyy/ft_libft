# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 21:36:31 by fzhang            #+#    #+#              #
#    Updated: 2025/05/05 21:36:36 by fzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ft_charstr.c ft_deci.c ft_hexa_pointer.c ft_printf.c ft_itoa_base.c test.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
NAME = testing

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:all clean fclean re

