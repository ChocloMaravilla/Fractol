HEADER	=	ft_prinft.h

NAME	=	printf.a

SRCS	=	ft_putnbr_fd.c ft_putstr_fd.c ft_printf.c

OBJS	=	$(SRCS:.c=.o)
CC	= 	cc
RM	= 	rm -f
LIBC	= 	ar rcs
FLAGS	= 	-Wall -Wextra -Werror

%.o : %.c Makefile ${HEADER} 
	${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJS} 
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
