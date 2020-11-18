/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:47:05 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/18 23:46:07 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

t_struct		ft_parse(const char *str, t_struct info)
{
	int		i;

	i = 0;
	if (ft_find_elem(str[i]) == 0)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			info.width = ft_atoi(&str[i]);
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
				i++;
		}
		else
			info.width = 0;
		if (str[i] == '.')
		{
			i++;
			if (str[i] >= '0' && str[i] <= '9')
				info.accur = ft_atoi(&str[i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		info.flag = ft_find_elem(str[i]);
	}
	else
	{
		info.flag = ft_find_elem(str[i]);
		info.width = 0;
	}
	return (info);
}
