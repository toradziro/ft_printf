/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:47:05 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/05 00:52:41 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_parse_width_n(const char *str, t_struct *info, int i)
{
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
		info->width = ft_atoi(&str[i]);
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			i++;
			if (str[i] == '-' && str[i + 1] == '*')
			{
				info->width = -ft_mod(va_arg(info->argument, int));
				i = i + 2;
			}
		}
	}
	else
		info->width = 0;
	return (i);
}

static int		ft_parse_width(const char *str, t_struct *info, int i)
{
	if (str[i] == '0')
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
		info->width = -ft_mod(va_arg(info->argument, int));
		i = i + 2;
	}
	else
		i = ft_parse_width_n(str, info, i);
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
	{
		info->accur = ft_atoi(&str[i]);
		if (info->accur < 0)
			info->accur = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

t_struct		ft_parse(const char *str, t_struct *info)
{
	int		i;

	i = 0;
	if (ft_find_elem(str[i]) == 0)
	{
		i = ft_parse_width(str, info, i);
		if (str[i] == '.')
		{
			i++;
			if (ft_find_elem(str[i]))
				info->accur = 0;
			else if (!ft_find_elem(str[i]))
				i = ft_parse_accur(str, info, i);
		}
		else
			info->accur = -1;
		info->flag = ft_find_elem(str[i]);
	}
	else
	{
		info->flag = ft_find_elem(str[i]);
		info->width = 0;
		info->accur = -1;
	}
	return (*info);
}
