#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_numlen(int num)
{
	int		i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

int			ft_hexlen(unsigned int num)
{
	int		i;

	i = 1;
	while (num /= 16)
		i++;
	return (i);
}

void		ft_putnbr_base(long long num, int base)
{
	char	*demical = "0123456789";
	char	*hex = "0123456789abcdef";

	if (num < 0)
		num = -num;
	if (num >= base)
	{
		ft_putnbr_base(num / base, base);
		ft_putnbr_base(num % base, base);
	}
	else
	{
		if (base == 10)
			write(1, &demical[num], 1);
		else if (base == 16)
			write(1, &hex[num], 1);
	}
}

void		ft_putnstr(char *s, int len)
{
	int		i;

	i = 0;
	while (s[i] && i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			print_flags(char *flags, char type, va_list ap)
{
	int		width;
	int		dot;
	int		precision;
	int		i;
	int		count;

	width = 0;
	dot = 0;
	precision = 0;
	i = 0;
	count = 0;
	while (flags[i])
	{
		if (ft_isdigit(flags[i]) && !dot)
			width = (width * 10) + (flags[i] - '0');
		else if (flags[i] == '.')
			dot = 1;
		else if (ft_isdigit(flags[i]) && dot)
			precision = (precision * 10) + (flags[i] - '0');
		i++;
	}

	char	*str;
	int		num;
	unsigned int	u_num;
	int		len;

	num = 0;
	u_num = 0;
	len = 0;
	if (type == 's')
	{
		if (!(str = va_arg(ap, char *)))
			str = "(null)";
		len = ft_strlen(str);
		if (dot)
		{
			if (precision > len)
				precision = len;
		}
		else
			precision = len;
		i = 0;
		while (i < width - precision)
		{
			write(1, " ", 1);
			count++;
			i++;
		}
		count += precision;
		ft_putnstr(str, precision);
	}
	else if (type == 'd' || type == 'x')
	{
		if (type == 'd')
		{
			num = va_arg(ap, int);
			len = ft_numlen(num);
		}
		else if (type == 'x')
		{
			u_num = va_arg(ap, unsigned int);
			len = ft_hexlen(u_num);
		}
		if (num == 0 && u_num == 0 && dot && precision == 0)
		{
			i = 0;
			while (i < width)
			{
				write(1, " ", 1);
				count++;
				i++;
			}
			free(flags);
			return (count);
		}
		if (precision < len)
			precision = len;
		if (num < 0)
			precision++;
		i = 0;
		while (i < width - precision)
		{
			write(1, " ", 1);
			count++;
			i++;
		}
		if (num < 0)
		{
			write(1, "-", 1);
			len++;
		}
		i = 0;
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
		count += precision;
		if (type == 'd')
			ft_putnbr_base(num, 10);
		else if (type == 'x')
			ft_putnbr_base(u_num, 16);
	}
	free(flags);
	return (count);
}

char		*ft_strndup(char *s, int len)
{
	int		i;
	char	*s2;

	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*find_type_identifier(char *s)
{
	int		i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '.'))
		i++;
	if (s[i] == 's' || s[i] == 'd' || s[i] == 'x')
		return (s + i);
	return (NULL);
}

int			check_format(va_list ap, char *s)
{
	int		i;
	char	*type;
	int		count;
	char	*format;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			type = find_type_identifier(s + i + 1);
			if (type)
			{
				format = ft_strndup(s + i, (type + 1) - (s + i));
				count += print_flags(format, *type, ap);
				i += ((type) - (s + i));
			}
			else
				i++;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int			ft_printf(const char *s, ...)
{
	int		count;
	va_list	ap;

	if (!s)
		return (-1);
	va_start(ap, s);
	count = check_format(ap, (char *)s);
	va_end(ap);
	return (count);
}
