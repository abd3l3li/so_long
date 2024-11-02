NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lX11 -lXext
RM = rm -rf

SRC = So_long/checks.c So_long/fill.c \
	  So_long/flood_fill.c  So_long/free.c \
	  So_long/main.c So_long/moves.c \
	  So_long/utils.c \
	  So_long/libft.c So_long/libft2.c \
	  So_long/get_next_line.c So_long/get_next_line_utils.c \


MLX = ./minilibx-linux/libmlx.a

OBJ = ${SRC:.c=.o}

all: ${NAME}

${MLX}:
	${MAKE} -C ./minilibx-linux

${NAME}: ${OBJ} ${MLX}
	${CC} ${CFLAGS} ${OBJ} ${MLX} ${LFLAGS} -o ${NAME}

clean:
	${MAKE} clean -C ./minilibx-linux
	${RM} ${OBJ}

fclean: clean
	${MAKE} clean -C ./minilibx-linux
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re