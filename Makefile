# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#              #
#    Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

INCDIR		= include
SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/print_char_string.c \
	$(SRC_DIR)/print_signed.c \
	$(SRC_DIR)/print_unsigned.c \
	$(SRC_DIR)/print_hex.c \
	$(SRC_DIR)/print_pointer.c \
	$(SRC_DIR)/utils.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES	= -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCDIR)/ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@if [ -d $(OBJ_DIR) ]; then rmdir $(OBJ_DIR) 2>/dev/null || true; fi

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

