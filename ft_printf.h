/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:51:03 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/25 19:27:48 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_struct
{
	va_list			argument;
	char			flag;
	int				accur;
	int				width;
	int				is_zero;
}					t_struct;

int 			ft_printf(const char *str, ...);
t_struct		ft_parse(const char *str, t_struct *info);
void			ft_print_int(t_struct *info);
int				ft_find_elem(char c);
void			ft_check_spec(t_struct *info);
void			ft_print_str(t_struct *info);
int				ft_len(long long int n);
void			ft_put_zero(int n);
void			ft_put_space(int n);
int				ft_mod(int n);
void			ft_putstr(char *s, int n);
void			ft_print_char(t_struct *info);
void			ft_print_hex_low(t_struct *info);
void			ft_print_hex_up(t_struct *info);
int				ft_atoi(const char *str);
void			ft_putnbr_fd(int n, int fd);
size_t 			ft_strlen(const char *str);

#endif
