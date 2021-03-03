#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;
	char	lf;

	lf = '\n';
	if (argc != 3)
	{
		write(1, &lf, 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
			{
				k = i - 1;
				while (k >= 0)
				{
					if (argv[1][i] == argv[1][k])
					{
						write(1, &argv[1][i], 1);
						break ;
					}
				}
			}
			j++;
		}
		i++;
	}
	write(1, &lf, 1);
	return (0);
}

