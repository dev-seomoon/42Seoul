#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *a = "hi";

	ft_printf("%04d\n", 12);
	printf("%04d\n", 12);
	ft_printf("%04d\n", -12);
	printf("%04d\n", -12);
	ft_printf("%d\n", 2147483647);
	printf("%d\n", 2147483647);
	ft_printf("%s\n", "HELLO");
	printf("%s\n", "HELLO");
	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');
	ft_printf("%.20x\n", 214);
	printf("%.20x\n", 214);
	ft_printf("%X\n", 214);
	printf("%X\n", 214);
	ft_printf("%p\n", a);
	printf("%p\n", a);
	ft_printf("%%\n");
	printf("%%\n");
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
