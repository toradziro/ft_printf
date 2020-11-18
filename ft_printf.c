/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:20:24 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/18 23:46:37 by ehillman         ###   ########.fr       */
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
	va_list		argument;
	int			ret;
	int			i;
	t_struct	info;

	ret = 0;
	i = 0;
	va_start(argument, str);
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
			info = ft_parse(&str[i], info);
			ft_put_width(argument, info);
		}
		while (!ft_find_elem(str[i]))
			i++;
		i++;
	}
	va_end(argument);
	return (0);
}
#include <stdio.h>
int		main(void)
{
	ft_printf("%-10d\n", 10);
	printf("%-10d\n", 10);
}
