/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon </var/mail/seomoon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:57:41 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/29 21:09:40 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = ft_strlen(s1);
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int		ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

int		ft_putstr(char *str)
{
	int	char_count;

	char_count = 0;
	while (str[char_count])
	{
		ft_putchar(str[char_count]);
		char_count++;
	}
	return (char_count);
}

int		get_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nbr;
	long	ln;

	ln = n;
	len = get_len(ln);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len--] = '\0';
	if (ln == 0)
		nbr[len] = '0';
	if (ln < 0)
	{
		nbr[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		nbr[len] = (ln % 10) + '0';
		ln /= 10;
		len--;
	}
	return (nbr);
}

int					get_len_u(unsigned int n)
{
	int				len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa_u(unsigned int n)
{
	int				len;
	char			*nbr;

	len = get_len_u(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	nbr[len] = '\0';
	len--;
	if (n == 0)
		nbr[len] = '0';
	while (n > 0)
	{
		nbr[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nbr);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

t_flags			ft_init_flags()
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int				ft_istype(int c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	else
		return (0);
}

int				ft_isflag(int c)
{
	if ((c == '-') || (c == '0') || (c == '.') || (c == '*'))
		return (1);
	else
		return (0);
}

int				ft_flag_dot(const char *save, int start, t_flags *flags, va_list args)
{
	int			i;

	i = start + 1;
	if (save[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[i]))
			flags->dot = flags->dot * 10 + save[i++] - '0';
	}
	return (i);
}

t_flags			ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags			ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_flags			ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = flags.width * 10 + c - '0';
	return (flags);
}

int				ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i] != '\0')
	{
		if (!ft_isdigit(save[i]) && !ft_istype(save[i]) && !ft_isflag(save[i]))
			break ;
		else if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		else if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, args);
		else if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		else if (save[i] == '*')
			*flags = ft_flag_width(args, *flags);
		else if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_istype(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int				ft_treat_width(t_flags flags, int strlen, int zero)
{
	int			char_count;
	int			print_width;

	char_count = 0;
	print_width = flags.width - strlen;
	while (print_width > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		print_width--;
		char_count++;
	}
	return (char_count);
}

int				ft_treat_char(char c, t_flags flags)
{
	int			char_count;

	if (flags.minus == 1)
		ft_putchar(c);
	char_count = ft_treat_width(flags, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (char_count + 1);
}

int				ft_treat_string(char *str, t_flags flags)
{
	int			i;
	int			len;
	int			char_count;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.dot >= 0 && flags.dot < len)
	{
		if (flags.minus == 1)
		{
			i = 0;
			while (i < flags.dot)
				ft_putchar(str[i++]);
		}
		char_count = ft_treat_width(flags, flags.dot, 0);
		if (flags.minus == 0)
		{
			i = 0;
			while (i < flags.dot)
				ft_putchar(str[i++]);
		}
		return (char_count + flags.dot);
	}
	if (flags.minus == 1)
		ft_putstr(str);
	char_count = ft_treat_width(flags, ft_strlen(str), 0);
	if (flags.minus == 0)
		ft_putstr(str);
	return (char_count + ft_strlen(str));
}

char			*ft_treat_precision(int n, int precision)
{
	int			i;
	int			j;
	int			len;
	char		*result;
	char		*nbr;

	len = get_len(n);
	if (n < 0)
	{
		len--;
		precision++;
	}
	if (len >= precision)
		result = ft_itoa(n);
	else
	{
		result = (char *)malloc(sizeof(char) * precision);
		if (!result)
			return (NULL);
		nbr = ft_itoa(n);
		i = 0;
		j = 0;
		if (n < 0)
		{
			result[i++] = '-';
			j++;
		}
		while (i < (precision - len))
			result[i++] = '0';
		while (i < precision)
			result[i++] = nbr[j++];
		result[i] = '\0';
		free(nbr);
	}
	return (result);
}

char			*ft_treat_precision_u(unsigned int n, int precision)
{
	int			i;
	int			j;
	int			len;
	char		*result;
	char		*nbr;

	len = get_len_u(n);
	if (len >= precision)
		result = ft_itoa_u(n);
	else
	{
		result = (char *)malloc(sizeof(char) * precision);
		if (!result)
			return (NULL);
		nbr = ft_itoa_u(n);
		i = 0;
		j = 0;
		if (n < 0)
		{
			result[i++] = '-';
			j++;
		}
		while (i < (precision - len))
			result[i++] = '0';
		while (i < precision)
			result[i++] = nbr[j++];
		result[i] = '\0';
		free(nbr);
	}
	return (result);
}

int				ft_treat_int(int n, t_flags flags)
{
	int			char_count;
	char		*str_num;

	if (flags.dot == 0 && n == 0)
	{
		char_count = ft_treat_width(flags, 0, 0);
		return (char_count);
	}
	else if (flags.dot >= 0)
	{
		str_num = ft_treat_precision(n, flags.dot);
		if (flags.minus == 1)
			ft_putstr(str_num);
		char_count = ft_treat_width(flags, ft_strlen(str_num), 0);
		if (flags.minus == 0)
			ft_putstr(str_num);
		return (char_count + ft_strlen(str_num));
	}
	if (flags.minus == 1)
	{
		str_num = ft_itoa(n);
		ft_putstr(str_num);
		char_count = ft_treat_width(flags, ft_strlen(str_num), 0);
		char_count = char_count + ft_strlen(str_num);
	}
	else
	{
		if (n < 0 && flags.zero)
		{
			ft_putchar('-');
			str_num = ft_itoa_u(n * -1);
			char_count = ft_treat_width(flags, ft_strlen(str_num) + 1, 1);
			ft_putstr(str_num);
			char_count = char_count + ft_strlen(str_num) + 1;
		}
		else
		{
			str_num = ft_itoa(n);
			char_count = ft_treat_width(flags, ft_strlen(str_num), flags.zero);
			ft_putstr(str_num);
			char_count = char_count + ft_strlen(str_num);
		}
	}
	return (char_count);
}

int				ft_treat_unint(unsigned int n, t_flags flags)
{
	int			char_count;
	char		*str_num;

	n = (unsigned int)(n + (4294967295 + 1));
	if (flags.dot == 0 && n == 0)
	{
		char_count = ft_treat_width(flags, 0, 0);
		return (char_count);
	}
	else if (flags.dot >= 0)
	{
		str_num = ft_treat_precision_u(n, flags.dot);
		if (flags.minus == 1)
			ft_putstr(str_num);
		char_count = ft_treat_width(flags, ft_strlen(str_num), 0);
		if (flags.minus == 0)
			ft_putstr(str_num);
		return (char_count + ft_strlen(str_num));
	}
	if (flags.minus == 1)
	{
		str_num = ft_itoa_u(n);
		ft_putstr(str_num);
		char_count = ft_treat_width(flags, ft_strlen(str_num), 0);
		char_count = char_count + ft_strlen(str_num);
	}
	else
	{
		str_num = ft_itoa_u(n);
		char_count = ft_treat_width(flags, ft_strlen(str_num), flags.zero);
		ft_putstr(str_num);
		char_count = char_count + ft_strlen(str_num);
	}
	return (char_count);
}

int				get_hex_len(unsigned long n)
{
	int			len;

	n = (uintmax_t)n;
	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char			*convert_demical_to_hex(unsigned long n, char letter)
{
	int			i;
	int			len;
	char		*hex;

	n = (uintmax_t)n;
	len = get_hex_len(n);
	hex = (char *)malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	hex[len--] = '\0';
	i = len;
	if (n == 0)
		hex[i] = '0';
	while (n > 0 && i >= 0)
	{
		if (n % 16 < 10)
			hex[i] = n % 16 + '0';
		else
			hex[i] = (n % 16) - 10 + letter;
		i--;
		n = n / 16;
	}
	return (hex);
}

char			*ft_treat_precision_hex(char *hex, int precision)
{
	int			len;
	int			i;
	char		*new_hex;

	len = ft_strlen(hex);
	if (precision <= len)
		return (hex);
	new_hex = (char *)malloc(sizeof(char) * (precision + 1));
	if (!new_hex)
		return (NULL);
	i = 0;
	while (i < (precision - len))
		new_hex[i++] = '0';
	len = 0;
	while (i < precision)
		new_hex[i++] = hex[len++];
	new_hex[i] = '\0';
	free(hex);
	return (new_hex);
}

int				ft_treat_hex(unsigned int n, t_flags flags, char letter)
{
	int			char_count;
	char		*hex;

	n = (unsigned int)(n + (4294967295 + 1));
	if (n == 0 && flags.dot == 0)
	{
		char_count = ft_treat_width(flags, 0, 0);
		return (char_count);
	}
	hex = convert_demical_to_hex(n, letter);
	if (flags.dot >= 0)
	{
		hex = ft_treat_precision_hex(hex, flags.dot);
		if (flags.minus == 1)
			ft_putstr(hex);
		char_count = ft_treat_width(flags, ft_strlen(hex), 0);
		if (flags.minus == 0)
			ft_putstr(hex);
		return (char_count + ft_strlen(hex));
	}
	if (flags.minus == 1)
	{
		ft_putstr(hex);
		char_count = ft_treat_width(flags, ft_strlen(hex), 0);
		char_count = char_count + ft_strlen(hex);
	}
	else
	{
		char_count = ft_treat_width(flags, ft_strlen(hex), flags.zero);
		ft_putstr(hex);
		char_count = char_count + ft_strlen(hex);
	}
	free(hex);
	return (char_count);
}

int				ft_treat_pointer(unsigned long pointer, t_flags flags)
{
	int			char_count;
	char		*addr;

	pointer = (uintmax_t)pointer;
	char_count = 2;
	if (pointer == 0 && flags.dot == 0)
	{
		if (flags.minus == 0)
			char_count += ft_treat_width(flags, char_count, 0);
		ft_putstr("0x");
		if (flags.minus == 1)
			char_count += ft_treat_width(flags, char_count, 0);
		return (char_count);
	}
	addr = convert_demical_to_hex(pointer, 'a');
	if (flags.minus == 0)
		char_count += ft_treat_width(flags, ft_strlen(addr) + 2, 0);
	ft_putstr("0x");
	ft_putstr(addr);
	if (flags.minus == 1)
		char_count += ft_treat_width(flags, ft_strlen(addr) + 2, 0);
	return (char_count + ft_strlen(addr));
}

int				ft_treat_percent(t_flags flags)
{
	int			char_count;

	if (flags.minus == 0)
		char_count = ft_treat_width(flags, 1, flags.zero);
	ft_putchar('%');
	if (flags.minus == 1)
		char_count = ft_treat_width(flags, 1, 0);
	return (char_count + 1);
}

int				ft_treat_type(char c, t_flags flags, va_list args)
{
	int			char_count;

	char_count = 0;
	if (c == 'c')
		char_count += ft_treat_char(va_arg(args, int), flags);
	else if (c == 's')
		char_count += ft_treat_string(va_arg(args, char *), flags);
	else if (c == 'd' || c == 'i')
		char_count += ft_treat_int(va_arg(args, int), flags);
	else if (c == 'p')
		char_count += ft_treat_pointer(va_arg(args, unsigned long), flags);
	else if (c == 'u')
		char_count += ft_treat_unint(va_arg(args, int), flags);
	else if (c == 'x')
		char_count += ft_treat_hex(va_arg(args, int), flags, 'a');
	else if (c == 'X')
		char_count += ft_treat_hex(va_arg(args, int), flags, 'A');
	else if (c == '%')
		char_count += ft_treat_percent(flags);
	return (char_count);
}

int				ft_treat_save(const char *save, va_list args)
{
	int			i;
	int			char_count;
	t_flags		flags;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (save[i] == '\0')
			break ;
		else if (save[i] == '%' && save[i + 1] != '\0')
		{
			while (save[i])
			{
				i = ft_flag_parse(save, ++i, &flags, args);
				if (ft_istype(save[i]))
				{
					char_count += ft_treat_type((char)flags.type, flags, args);
					break ;
				}
				else
					char_count += ft_putchar(save[i]);
			}
		}
		else if (save[i] != '%') 
			char_count += ft_putchar(save[i]);
		i++;
	}
	return (char_count);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			char_count;
	const char	*save;

	char_count = 0;
	save = ft_strdup(format);
	va_start(args, format);
	char_count = ft_treat_save(save, args);
	va_end(args);
	free((void *)save);
	return (char_count);
}
/*
int				main()
{
   printf("printf: %0*\n", 2, 0, 8);
   ft_printf("ft_printf: %0*.*x", 2, 0, 8);
}
*/
int				main()
{
   int		a = -4;
   int		b = 0;
   char	c = 'a';
   int		d = 2147483647;
   int		e = -2147483648;
   int		f = 42;
   int		g = 25;
   int		h = 4200;
   int		i = 8;
   int		j = -12;
   int		k = 123456789;
   int		l = 0;
   int		m = -12345678;
   char	*n = "abcdefghijklmnop";
   char	*o = "-a";
   char	*p = "-12";
   char	*q = "0";
   char	*r = "%%";
   char	*s = "-2147483648";
   char	*t = "0x12345678";
   char	*u = "-0";

	//printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12
	//ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d); //T12
	//PRINT(" --- Return : %d\n", PRINT("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	// ^ Theoriquement un comportement indefini mais testé par la moulinette
    //PRINT(" --- Return : %d\n", PRINT("(null)"));
	//PRINT(" --- Return : %d\n", PRINT(""));
	
    printf("|%0*.%|\n", 3);
    ft_printf("|%0*.%|\n", 3);
	return (0);
}

