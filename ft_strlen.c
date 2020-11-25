/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 01:29:29 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/25 19:28:07 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t 	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
