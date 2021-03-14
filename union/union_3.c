#include <unistd.h>

int	dupl_check(char *str, char ch, int length)
{
	int	i;

	if (!str)
		return (-1);
	
	i = 0;
	while (str[i] != '\0' && i < length)
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	if (ch == '\0' && str[i] == '\0')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc == 3)
	{	
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (dupl_check(argv[1], argv[1][i], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (dupl_check(argv[1], argv[2][j], i) == 0)
			{
				if (dupl_check(argv[2], argv[2][j], j) == 0)
					write(1, &argv[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
