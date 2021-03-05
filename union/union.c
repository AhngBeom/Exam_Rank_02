#include <unistd.h>

int	dupl_check(char *str, int range, char ch)
{
	while (range >= 0)
	{
		if (str[range] == ch)
			return (1);
		range--;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	char	lf;

	lf = '\n';
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (!dupl_check(argv[1], i - 1, argv[1][i]))
				write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (!dupl_check(argv[1], i - 1, argv[2][j]) && !dupl_check(argv[2], j - 1, argv[2][j]))
				write(1, &argv[2][j], 1);
			j++;
		}

	}
	write(1, &lf, 1);
	return (0);
}

