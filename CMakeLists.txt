cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf
        ft_atoi.c
        ft_print_adress.c
        ft_print_char.c
        ft_print_hex_low.c
        ft_print_hex_up.c
        ft_print_int.c
        ft_print_percent.c
        ft_print_str.c
        ft_print_unsigned.c
        ft_printf.c
        ft_printf.h
        ft_printf_utils.c
        ft_putnbr_fd.c
        ft_strlen.c
        parser.c)
