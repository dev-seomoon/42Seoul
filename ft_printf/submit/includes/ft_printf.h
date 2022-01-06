/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:17:24 by seomoon           #+#    #+#             */
/*   Updated: 2020/12/08 23:35:55 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_treat_save(char *save, va_list args);

int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putstr_len(char *str, int len);
int				get_len_u(unsigned int n);
char			*ft_itoa_u(unsigned int n);

int				ft_isdigit(int c);
int				ft_istype(int c);
int				ft_isflag(int c);
t_flags			ft_init_flags();
t_flags			ft_flag_minus(t_flags flags);
t_flags			ft_flag_width(va_list args, t_flags flags);
t_flags			ft_flag_digit(char c, t_flags flags);
int				ft_flag_dot(const char *save, int st, t_flags *flags,
				va_list args);
int				ft_flag_parse(const char *save, int i, t_flags *flags,
				va_list args);
int				ft_treat_width(t_flags flags, int len, int zero);
char			*ft_treat_precision(int n, int precision);
char			*ft_treat_precision_u(unsigned int n, int precision);
char			*ft_treat_precision_hex(char *hex, int precision);

int				ft_treat_char(char c, t_flags flags);
int				ft_put_int(char *str_num, t_flags flags, int zero);
int				ft_treat_int(int n, t_flags flags);
int				ft_treat_unint(unsigned int n, t_flags flags);
int				ft_treat_string(char *str, t_flags flags);
int				get_hex_len(unsigned long n);
char			*convert_demical_to_hex(unsigned long n, char letter);
int				ft_treat_hex(unsigned int n, t_flags flags, char letter);
int				ft_treat_pointer(unsigned long pointer, t_flags flags);
int				ft_treat_percent(t_flags flags);
int				ft_treat_type(char c, t_flags flags, va_list args);

#endif
