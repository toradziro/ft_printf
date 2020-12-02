/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 01:27:22 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/04 19:48:40 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, t_struct *info)
{
	char			c;
	unsigned int	nu;

	if (n < 0)
	{
		info->p_len += write(fd, "-", 1);
		nu = n * -1;
	}
	else
		nu = n;
	if (nu > 9)
	{
		c = nu % 10 + '0';
		ft_putnbr_fd((nu / 10), fd, info);
		info->p_len += write(fd, &c, 1);
	}
	if (nu <= 9)
	{
		c = nu + '0';
		info->p_len += write(fd, &c, 1);
	}
}
