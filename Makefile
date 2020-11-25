NAME 	= 	libftprintf.a

SRC		= 	ft_printf.c ft_print_char.c \
			ft_print_hex_low.c ft_print_hex_up.c \
			ft_print_int.c ft_print_str.c \
			ft_printf_utils.c \
			parser.c ft_atoi.c ft_putnbr_fd.c \
			ft_strlen.c

OBJS	=	ft_printf.o ft_print_char.o \
            ft_print_hex_low.o ft_print_hex_up.o \
            ft_print_int.o ft_print_str.o \
            ft_printf_utils.o \
            parser.o ft_atoi.o ft_putnbr_fd.o \
            ft_strlen.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${FLAGS} ${SRC}
			ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -rf *.o

fclean: clean
	rm -rf libftprintf.a

.PHONY: all clean fclean
