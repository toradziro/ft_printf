/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:47:05 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/27 00:39:24 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Парс звездочки и парс 0 вынести в две отдельные функции и в них заполнить с-
 * трукру
*/

static int		ft_parse_width(const char *str, t_struct *info, int i)
{
	if (str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		info->is_zero = 1;
		i++;
	}
	else
		info->is_zero = 0;
	if (str[i] == '*')
	{
		info->width = va_arg(info->argument, int);
		i++;
	}
	else if (str[i] == '-' && str[i + 1] == '*')
	{
		info->width = -va_arg(info->argument, int);
		i = i + 2;
	}
	else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
		info->width = ft_atoi(&str[i]);
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
	}
	else
		info->width = 0;
//	if (info->width == 0)
//		info->width = 1;
	return (i);
}

static int		ft_parse_accur(const char *str, t_struct *info, int i)
{
	if (str[i] == '*')
	{
		info->accur = va_arg(info->argument, int);
		i++;
	}
	else if (str[i] >= '0' && str[i] <= '9')
		info->accur = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

t_struct		ft_parse(const char *str, t_struct *info)
{
	int		i;

	i = 0;
	if (str[i] == '.' && ft_find_elem(str[i + 1]))
	{
		info->width = -1;
		info->accur = -1;
		i++;
	}
	else if (ft_find_elem(str[i]) == 0)
	{
		i = ft_parse_width(str, info, i);
		if (str[i] == '.')
		{
			i++;
			if (ft_find_elem(str[i]) && info->width)
		 		info->accur = -2;
			else if (!ft_find_elem(str[i]))
				i = ft_parse_accur(str, info, i);
		}
		else
			info->accur = -1;
		info->flag = ft_find_elem(str[i]);

//		ft_putnbr_fd(info->width, 1);
//		write(1, "\n", 1);
	}
	else
	{
		info->flag = ft_find_elem(str[i]);
		info->width = 0;
		info->accur = -1;
	}
		//  ft_putnbr_fd(info->accur, 1);
		//  write(1, "\n", 1);
	return (*info);
}
