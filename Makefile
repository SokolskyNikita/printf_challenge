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
	$(RM)	$(TEST_BIN)

fclean:	clean
	$(RM)	$(NAME)
	$(RM)	$(SAMPLES)
	find . \( -name "*.gcno" -o -name "*.gcda" -o -name "*.gcov" \) -delete 2>/dev/null || true

re:	fclean all

bonus:	all

.SILENT:

# ------------------------------ Tests & Coverage ------------------------------
TEST_DIR	=	tests
SAMPLE_DIR	=	samples
COV_FLAGS	=	-fprofile-arcs -ftest-coverage

TEST_SRCS	=	$(TEST_DIR)/test_utils.c \
				$(TEST_DIR)/test_all.c

TEST_BIN	=	$(TEST_DIR)/runner

$(TEST_BIN):	$(NAME) $(TEST_SRCS)
	$(CC)	$(CFLAGS)	$(INCLUDES)	$(TEST_SRCS)	-L.	-lftprintf	-o	$(TEST_BIN)

test:	$(TEST_BIN)
	./$(TEST_BIN)

coverage:
	$(MAKE)	fclean
	$(MAKE)	CC=gcc CFLAGS="$(CFLAGS) $(COV_FLAGS)"
	gcc	$(CFLAGS)	$(INCLUDES)	$(TEST_SRCS)	-L.	-lftprintf	-o	$(TEST_BIN)	$(COV_FLAGS)
	./$(TEST_BIN)
	gcov -b -o $(OBJ_DIR) $(SRC_DIR)/*.c >/dev/null || true
	if ls *.gcov >/dev/null 2>&1; then \
		if grep -R "^#####:" *.gcov >/dev/null 2>&1; then \
			echo "Coverage check failed: some lines not executed." ; \
			grep -R "^#####:" -n *.gcov | head -n 50 ; \
			exit 1 ; \
		else \
			echo "All source files at 100% line coverage." ; \
		fi ; \
	else \
		echo "Coverage data not generated. Ensure gcc/gcov are installed." ; \
		exit 1 ; \
	fi

# --------------------------------- Samples -----------------------------------
SAMPLES		=	$(SAMPLE_DIR)/basic $(SAMPLE_DIR)/edge

$(SAMPLE_DIR)/basic:	$(NAME) $(SAMPLE_DIR)/basic.c
	$(CC)	$(CFLAGS)	$(INCLUDES)	$(SAMPLE_DIR)/basic.c	-L.	-lftprintf	-o	$(SAMPLE_DIR)/basic

$(SAMPLE_DIR)/edge:	$(NAME) $(SAMPLE_DIR)/edge.c
	$(CC)	$(CFLAGS)	$(INCLUDES)	$(SAMPLE_DIR)/edge.c	-L.	-lftprintf	-o	$(SAMPLE_DIR)/edge

samples:	re $(SAMPLES)

.PHONY:	all clean fclean re bonus

