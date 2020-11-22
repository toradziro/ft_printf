/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:20:24 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/22 16:01:00 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** идем по строке и доходим до %, после этого вызываем парсер, который парсит до
** флага и выставляет значения полей структуры после окончания парса мы возвращ-
** аем структуру и передаем ее в печать ширины, потом в печать точности и после-
** вместе с va_list в печать аргумента
**
** положительная ширина - это printf("%-10d", 5); "5         "
** отрицательная ширина - это printf("%10d", 5); "         5"
*/

#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	int			ret;
	int			i;
	t_struct	info;

	ret = 0;
	i = 0;
	va_start(info.argument, str);
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
			ret++;
		}
		if (str[i] == '\0')
			break ;
		if (str[i] == '%')
		{
			i++;
			info = ft_parse(&str[i], &info);
			ft_check_spec(&info);
		}
		while (!ft_find_elem(str[i]))
			i++;
		i++;
	}
	va_end(info.argument);
	return (0);
}

void		ft_check_spec(t_struct *info)
{
	if (info->flag == 'i' || info->flag == 'd')
		ft_print_int(info);
	else if (info->flag == 's')
		ft_print_str(info);
/*	else if (info->flag == 'c')
		ft_print_char(info);
	else if (info->flag == 'x')
		ft_print_hex_low(info);
	else if (info->flag == 'X')
		ft_print_hex_up(info);
	else if (info->flag == 'p')
		ft_print_adress(info);
	else if (info->flag == 'u')
		ft_print_unsigned(info); */
}

#include <stdio.h>
int		main(void)
{
	ft_printf("test 1 'd': %*.*d\n", 15, 10, 5); //+ширина > точности
	printf("test 1 'd': %*.*d\n", 15, 10, 5);
	ft_printf("test 2 'd': %*.*d\n", 10, 15, 5); //+ширина < точности
	printf("test 2 'd': %*.*d\n", 10, 15, 5);
	ft_printf("test 3 'd': %*.*d\n", -5, 15, 5); //-ширина
	printf("test 3 'd': %*.*d\n", -5, 15, 5);
	ft_printf("Test 4 'd': %.10d\n", 5); // точность больше числа
	printf("test 4 'd': %.10d\n", 5);
	ft_printf("Test 5 'd': %.1d\n", 15); // точность меньше числа
	printf("test 5 'd': %.1d\n", 15);
	ft_printf("test 6 'd': %10d\n", 15); // ширина больше числа
	printf("test 6 'd': %10d\n", 15);
	ft_printf("test 7 'd': %1d\n", 15); // ширина меньше числа
	printf("test 7 'd': %1d\n", 15);
	ft_printf("test 8 'd': %-10d\n", 15); // ширина отрицательная
	printf("test 8 'd': %-10d\n", 15);
	ft_printf("test 9 'd': %010d\n", 15); // ширина 0
	printf("test 9 'd': %010d\n", 15);
	ft_printf("test 10 'd': %d, %i, %d, %d, %i\n", 15, 123123, 43, 56564, -3478534);
	printf("test 10 'd': %d, %i, %d, %d, %i\n", 15, 123123, 43, 56564, -3478534);
	ft_printf("test 1 's': %40s\n", "Hello my dear friend"); // +ширина
	printf("test 1 's': %40s\n", "Hello my dear friend");
	ft_printf("test 2 's': %-40s\n", "Hello my dear friend"); // -ширина
	printf("test 2 's': %-40s\n", "Hello my dear friend");
	ft_printf("test 3 's': %.40s\n", "Hello my dear friend"); // точность больше строки
	printf("test 3 's': %.40s\n", "Hello my dear friend");
	ft_printf("test 4 's': %.1s\n", "Hello my dear friend"); // точность меньше строки
	printf("test 4 's': %.1s\n", "Hello my dear friend");
	ft_printf("test 5 's': %100.100s\n", "Hello my dear friend"); // +ширина и точность больше строки
	printf("test 5 's': %100.100s\n", "Hello my dear friend");
	ft_printf("test 6 's': %-40.40s\n", "Hello my dear friend"); // -ширина и точность больше строки
	printf("test 6 's': %-40.40s\n", "Hello my dear friend");
	ft_printf("test 7 's': %40.5s\n", "Hello my dear friend"); // +ширина и точность меньше строки
	printf("test 7 's': %40.5s\n", "Hello my dear friend");
	ft_printf("test 8 's': %-40.5s\n", "Hello my dear friend"); // -ширина и точность меньше строки
	printf("test 8 's': %-40.5s\n", "Hello my dear friend");
}
