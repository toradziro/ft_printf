/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:51:03 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 23:15:06 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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
	int				p_len;
}					t_struct;

int					ft_printf(const char *str, ...);
t_struct			ft_parse(const char *str, t_struct *info);
void				ft_print_int(t_struct *info);
int					ft_find_elem(char c);
void				ft_check_spec(t_struct *info);
void				ft_print_str(t_struct *info);
int					ft_len(long long int n);
void				ft_put_zero(int n, t_struct *info);
void				ft_put_space(int n, t_struct *info);
long				ft_mod(long n);
void				ft_putstr(char *s, int n, t_struct *info);
void				ft_print_char(t_struct *info);
void				ft_print_hex_low(t_struct *info);
void				ft_print_hex_up(t_struct *info);
int					ft_atoi(const char *str);
void				ft_putnbr(long n, int fd, t_struct *info);
size_t				ft_strlen(const char *str);
void				ft_print_percent(t_struct *info);
void				ft_print_unsigned(t_struct *info);
void				ft_print_adress(t_struct *info);
void				ft_putnbr_base(unsigned int n, t_struct *info, int alpha);
int					ft_len_hex(long long int n);
void				ft_print_spaces_hex_l(int num, int arg, int edge,
					t_struct *info);
void				ft_print_zeros_hex_l(int num, int arg, int edge,
					t_struct *info);
void				ft_print_spaces_hex_u(int num, int arg, int edge,
					t_struct *info);
void				ft_print_zeros_hex_u(int num, int arg, int edge,
					t_struct *info);
void				ft_putnbr_u_fd(unsigned int n, t_struct *info);
void				ft_print_spaces_u(int num, unsigned int arg, int edge,
					t_struct *info);
void				ft_print_zeros_u(int num, unsigned int arg, int edge,
					t_struct *info);
void				ft_putnbr_p(unsigned long nu, t_struct *info);
void				ft_print_spaces_p(int num, unsigned long arg, int edge,
					t_struct *info);
void				ft_print_zeros_p(int num, unsigned long arg, int edge,
					t_struct *info);
void				ft_print_spaces_int(int num, long arg, int edge,
					t_struct *info);
void				ft_print_zeros_int(int num, long arg, int edge,
					t_struct *info);
void				ft_print_positive_int_next(t_struct *info,
					int arg, int len);
void				ft_print_positive_int(t_struct *info,
					int arg, int len);

#endif
