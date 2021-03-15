#include <stdio.h>

int	ft_printf(const char *, ...);

int	main()
{
	ft_printf("%10.2s\n", "toto");
	ft_printf("Magic %s is %5d", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%");
	ft_printf("%0");
	ft_printf("%05");

	return (0);
}

