#include "get_next_line.h"

int main()
{
	int ret;
	char	*line;

	line = NULL;
	while((ret = get_next_line(&line)) > 0)
	{
		printf("line : %s\n", line);
		free(line);
		line = NULL;
	}
	printf("line : %s", line);
	free(line);
	line = NULL;
	
	return 0;
}
