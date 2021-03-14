#include <stdio.h>
#include <limits.h>

int ft_printf(const char *, ... );

int main()
{
	printf(" (return : %d)\n", ft_printf("Hello World !"));

	printf("=============String Format===============\n");
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.0s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.3s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.7s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.3s|", NULL));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.7s|", NULL));
	
	
	printf("=============Integer Format===============\n");
	printf(" (return : %d)\n", ft_printf("ft_printf : |%d|", 0));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%d|", 3));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.0d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.3d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.7d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.5d|", -2147483648));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.15d|", -2147483648 - 1));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.5d|", 2147483647));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.14d|", 2147483647 + 1));

	
	printf("=============Hex Format===============\n");
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.x|", 65535));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.0x|", 65535));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.3x|", 65535));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.6x|", 65535));
	
	printf("=============Exception Format===============\n");
	printf(" (return : %d)\n", ft_printf("ft_printf : |%|"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%5|"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%05|"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%-5|"));
	
	return (0);
}
