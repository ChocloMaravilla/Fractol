NAME = fractol

SRC = src/fractol_checking.c\
	  src/fractol_color.c\
	  src/fractol_draw_julia.c\
	  src/fractol_draw_mandelbrot.c\
	  src/fractol_events.c\
	  src/fractol_main.c\
	  src/fractol_mlx_function.c\
	  src/fractol_math.c\
	  src/fractol_mouse_hooks.c

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

LIBFT_A = Libs/ft_libft/libft.a

PRINTF_A = Libs/ft_printf/printf.a

MLX_A = mlx_linux/libmlx_Linux.a

all: makelibft makemlx $(NAME)

makelibft:
	make -C Libs/ft_libft
	make -C Libs/ft_printf

makemlx:
	make -C mlx_linux

$(NAME): $(OBJS)  $(PRINTF_A) $(LIBFT_A) $(MLX_A)
	${CC} $(CFLAGS) $(OBJS) $(PRINTF_A) $(LIBFT_A) $(MLX_A) -lXext -lX11 -lm -lz -o $(NAME) 

# -L mlx_test -I mlx_test

%.o:%.c Makefile fractol.h
	${CC} $(CFLAGS) -c $< -o $@

# -Imlx_linux/mlx.h

clean:
	rm -rf $(OBJS)
	make clean -C Libs/ft_libft
	make clean -C Libs/ft_printf
	make clean -C mlx_linux

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re makelibft
