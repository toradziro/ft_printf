/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:47:05 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/22 11:01:46 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Парс звездочки и парс 0 вынести в две отдельные функции и в них заполнить с-
 * трукру
*/

int		ft_find_elem(char c)
{
	char	*flags;
	int		i;

	flags = "cspdiuxX";
	i = 0;
	while (flags[i] != '\0')
	{
		if (c == flags[i])
			return ((int)flags[i]);
		i++;
	}
	return (0);
}

t_struct		ft_parse(const char *str, t_struct *info)
{
	int		i;

	i = 0;
	if (ft_find_elem(str[i]) == 0)
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
			info->width = 1;
		if (info->width == 0)
			info->width = 1;
		if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
			{
				info->accur = va_arg(info->argument, int);
				i++;
			}
			else if (str[i] >= '0' && str[i] <= '9')
				info->accur = ft_atoi(&str[i]);
			else
				info->accur = 1;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			info->accur = 1;
		info->flag = ft_find_elem(str[i]);
	}
	else
	{
		info->flag = ft_find_elem(str[i]);
		info->width = 1;
		info->accur = 1;
	}
	return (*info);
}
