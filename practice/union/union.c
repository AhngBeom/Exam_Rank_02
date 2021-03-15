#include <unistd.h>

int	dupl_check(char *str, char ch, int range)
{
	if (!str)
		return (-1);
	while (range >= 0)
	{
		if (str[range] == ch)
			return (0);
		range--;
	}
	return (1);
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
			if (dupl_check(argv[1], argv[1][i], i - 1))
				write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (dupl_check(argv[1], argv[2][j], i - 1))
			{
				if (dupl_check(argv[2], argv[2][j], j - 1))
					write(1, &argv[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
