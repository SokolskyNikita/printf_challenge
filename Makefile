NAME		=	libftprintf.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS	=	rcs
RM		=	rm -f

SRC_DIR	=	src
OBJ_DIR	=	obj

SRCS		=	$(SRC_DIR)/ft_printf.c \
				$(SRC_DIR)/print_char_str.c \
				$(SRC_DIR)/print_signed.c \
				$(SRC_DIR)/print_unsigned.c \
				$(SRC_DIR)/print_hex.c \
				$(SRC_DIR)/print_pointer.c \
				$(SRC_DIR)/print_base.c \
				$(SRC_DIR)/utils.c

OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES	=	-I.

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
	$(AR)	$(ARFLAGS)	$(NAME)	$(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c ft_printf.h
	$(CC)	$(CFLAGS)	$(INCLUDES)	-c	$<	-o	$@

clean:
	$(RM)	$(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re:	fclean all

bonus:	all

.PHONY:	all clean fclean re bonus

