NAME 	= 	Libftprintf.a

SRC		= 	ft_printf.c ft_print_char.c \
			ft_print_hex_low.c ft_print_hex_up.c \
			ft_print_int.c ft_print_str.c \
			ft_printf_utils.c \
			parser.c

OBJS	=	${SRC:.c = .o}

CC = gcc

#FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
clean:
	rm -rf ${OBJS}
fclean:
	clean
	rm -rf Libftprintf.a
