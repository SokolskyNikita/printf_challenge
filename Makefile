# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 00:00:00 by student           #+#    #+#              #
#    Updated: 2025/09/10 00:00:00 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	src/ft_printf.c \
				src/print_char_str.c \
				src/print_signed.c \
				src/print_unsigned.c \
				src/print_hex.c \
				src/print_pointer.c \
				src/print_base.c \
				src/utils.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o:		%.c ft_printf.h
			$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re bonus