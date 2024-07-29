NAME = fractol
SRC = src/fractol_main.c\
	  src/fractol_checking.c\
	  src/fractol_mlx_function.c\
	  src/fractol_draw_mandelbrot.c\
	  src/fractol_events.c\
	  src/fractol_mouse_hooks.c\
	  src/fractol_draw_julia.c
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
RM = rm -f
LIBFT_A = Libs/ft_libft/libft.a
MLX_A = mlx_linux/libmlx_Linux.a
all: makelibft makemlx $(NAME)

makelibft:
	make -C Libs/ft_libft

makemlx:
	make -C mlx_linux

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	${CC} $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) -lXext -lX11 -lm -lz -o $(NAME)


./src/%.o: ./src/%.c fractol_header.h Makefile
	${CC} $(CFLAGS) -c $< -o $@


#${OBJ_D}%.o: ${SRC_D}%.c Makefile
	#@${CC} ${CFLAGS} -MMD -c $< -o $@


clean:
	$(RM) $(OBJS)
	make clean -C Libs/ft_libft
	make clean -C mlx_linux

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re makelibft
