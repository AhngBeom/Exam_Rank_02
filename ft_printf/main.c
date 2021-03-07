#include <stdio.h>

int ft_printf(const char *, ... );

int main()
{

	printf(" (return : %d)\n", ft_printf("%9.1s", NULL));
	
	/*
	printf(" (return : %d)\n", printf("   printf : |%10.s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.s|", "abcde"));
	printf(" (return : %d)\n", printf("   printf : |%10.0s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.0s|", "abcde"));
	printf(" (return : %d)\n", printf("   printf : |%10.3s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.3s|", "abcde"));
	printf(" (return : %d)\n", printf("   printf : |%10.7s|", "abcde"));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.7s|", "abcde"));
	
	
	
	printf(" (return : %d)\n", printf("   printf : |%10.d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.d|", 12345));
	printf(" (return : %d)\n", printf("   printf : |%10.0d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.0d|", 12345));
	printf(" (return : %d)\n", printf("   printf : |%10.3d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.3d|", 12345));
	printf(" (return : %d)\n", printf("   printf : |%10.7d|", 12345));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.7d|", 12345));
	
	
	printf(" (return : %d)\n", printf("   printf : |%10.x|", 255));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.x|", 255));
	printf(" (return : %d)\n", printf("   printf : |%10.0x|", 255));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.0x|", 255));
	printf(" (return : %d)\n", printf("   printf : |%10.1x|", 255));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.1x|", 255));
	printf(" (return : %d)\n", printf("   printf : |%10.5x|", 255));
	printf(" (return : %d)\n", ft_printf("ft_printf : |%10.5x|", 255));
	*/
	return (0);
}
