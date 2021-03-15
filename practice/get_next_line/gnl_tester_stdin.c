#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	get_next_line(char **line);

int main()
{
	int		j;
	char	*line = 0;

	j = 1;
	while (get_next_line(&line) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	free(line);
}
