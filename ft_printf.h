/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:51:03 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/18 23:05:05 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_struct
{
	char			flag;
	int				accur;
	int				width;
//	int				is_minus;
//	int				is_zero;
}					t_struct;

t_struct		ft_parse(const char *str, t_struct info);
void			ft_put_width(va_list argument, t_struct info);
int				ft_find_elem(char c);

#endif
