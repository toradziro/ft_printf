/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:20:24 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/22 11:38:21 by ehillman         ###   ########.fr       */
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
			ft_put_width(&info);
		}
		while (!ft_find_elem(str[i]))
			i++;
		i++;
	}
	va_end(info.argument);
	return (0);
}
#include <stdio.h>
int		main(void)
{
	ft_printf("test 1: %*.*d\n", 15, 10, 5); //+ширина > точности
	printf("test 1: %*.*d\n", 15, 10, 5);
	ft_printf("test 2: %*.*d\n", 10, 15, 5); //+ширина < точности
	printf("test 2: %*.*d\n", 10, 15, 5);
	ft_printf("test 3: %*.*d\n", -5, 15, 5); //-ширина
	printf("test 3: %*.*d\n", -5, 15, 5);
	ft_printf("Test 4: %.10d\n", 5); // точность больше числа
	printf("test 4: %.10d\n", 5);
	ft_printf("Test 5: %.1d\n", 15); // точность меньше числа
	printf("test 5: %.1d\n", 15);
	ft_printf("test 6: %10d\n", 15); // ширина больше числа
	printf("test 6: %10d\n", 15);
	ft_printf("test 7: %1d\n", 15); // ширина меньше числа
	printf("test 7: %1d\n", 15);
	ft_printf("test 8: %-10d\n", 15); // ширина отрицательная
	printf("test 8: %-10d\n", 15);
	ft_printf("test 9: %010d\n", 15); // ширина 0
	printf("test 9: %010d\n", 15);
	ft_printf("test 10: %d, %i, %d, %d, %i\n", 15, 123123, 43, 56564, -3478534);
	printf("test 10: %d, %i, %d, %d, %i\n", 15, 123123, 43, 56564, -3478534);
}
