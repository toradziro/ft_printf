all:
	gcc ft_printf.c ft_printf.h ft_print_char.c ft_print_hex_low.c ft_print_int.c parser.c ft_printf_utils.c ft_print_str.c ft_print_hex_up.c libft/libft.a
	rm -f ft_printf.h.gch
