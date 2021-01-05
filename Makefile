# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 00:56:46 by ehillman          #+#    #+#              #
#    Updated: 2020/12/05 01:23:47 by ehillman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRC		= 	ft_printf.c ft_print_char.c \
			ft_print_hex_low.c ft_print_hex_up.c \
			ft_print_int.c ft_print_str.c \
			ft_printf_utils.c \
			ft_parser.c ft_atoi.c ft_putnbr_fd.c \
			ft_strlen.c ft_print_percent.c \
			ft_print_unsigned.c ft_print_adress.c \
			ft_utils_hex.c ft_utils_u.c \
			ft_utils_p.c ft_utils_int.c

OBJS	=	ft_printf.o ft_print_char.o \
			ft_print_hex_low.o ft_print_hex_up.o \
			ft_print_int.o ft_print_str.o \
			ft_printf_utils.o \
			ft_parser.o ft_atoi.o ft_putnbr_fd.o \
			ft_strlen.o ft_print_percent.o \
			ft_print_unsigned.o ft_print_adress.o \
			ft_utils_hex.o ft_utils_u.o \
			ft_utils_p.o ft_utils_int.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${FLAGS} ${SRC}
			ar -rcs ${NAME} ${OBJS}

all: 		${NAME}

clean:
			rm -rf ${OBJS}

fclean:	clean
			rm -rf libftprintf.a

re: 		fclean all

.PHONY: all clean fclean
