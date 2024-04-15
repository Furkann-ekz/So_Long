NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL

SRCS =	main.c			\
		ft_split.c		\
		game.c			\
		locations.c		\
		map_control.c	\
		map_control2.c	\
		map.c			\
		reader.c		\
		move.c			\
		finish.c		\

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

B_NAME = so_long_bonus
BSRCS =	./bonus/bonus_finish.c		\
 		./bonus/bonus_ft_split.c		\
		./bonus/bonus_game.c			\
		./bonus/bonus_locations.c		\
		./bonus/bonus_main.c			\
		./bonus/bonus_map_control.c	\
		./bonus/bonus_map_control2.c	\
		./bonus/bonus_map.c			\
		./bonus/bonus_move.c			\
		./bonus/bonus_reader.c		\
		./bonus/enemy_move.c			\
		./bonus/ft_itoa.c			\

BOBJS = $(BSRCS:.c=.o)

all: ${NAME}

$(MINI):
	make -C ./mlx &> /dev/null

$(NAME): $(MINI) $(OBJS)
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
	gcc -Wall -Wextra -Werror -c $(SRCS)


%.o: %.c
	${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

bonus: $(B_NAME)

$(B_NAME): $(MINI) $(BOBJS)
	$(CC) ${CFLAGS} $(BOBJS) -o $(B_NAME)

clean:
	rm -rf ${OBJS}
	rm -rf $(BOBJS)
	make clean -C mlx/

fclean: clean
	rm -rf ${NAME}
	rm -rf $(B_NAME)
	make clean -C mlx/

re: fclean all
.PHONY: fclean re all clean bonus
