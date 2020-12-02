/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:20:24 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/01 22:32:57 by ehillman         ###   ########.fr       */
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
	info.p_len = 0;
	if (!str)
		return (0);
	va_start(info.argument, str);
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			info.p_len += write(1, &str[i], 1);
			i++;
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
	return (info.p_len);
}

void		ft_check_spec(t_struct *info)
{
	if (info->flag == 'i' || info->flag == 'd')
		ft_print_int(info);
	else if (info->flag == 's')
		ft_print_str(info);
	else if (info->flag == 'c')
		ft_print_char(info);
	else if (info->flag == 'x')
		ft_print_hex_low(info);
	else if (info->flag == 'X')
		ft_print_hex_up(info);
	else if (info->flag == 'p')
		ft_print_adress(info);
	else if (info->flag == 'u')
		ft_print_unsigned(info);
	else if (info->flag == '%')
		ft_print_percent(info);
}
