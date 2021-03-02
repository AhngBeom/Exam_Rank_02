#include "get_next_line.h"

int main()
{
	int rfd;
	int rtn;
	//char buffer[BUF_SIZE];
	char	*line;

	if((rfd = open("./text", O_RDONLY)) == -1)
	{ 
		printf("FILE READ OPEN ERROR"); 
		return 1;
	}
	while(1)
	{ 
		if((rtn = get_next_line(&line)) == -1)
		{ 
			printf("GNL ERROR");
			return 1;
		} 
		if(rtn == 0)
			break;
		printf("%s\n", line);
	}
/*
	while(1)
	{ 
		if((len = read(rfd, buffer, BUF_SIZE)) == -1)
		{ 
			printf("READ ERROR");
			return 1;
		} 
		if(len == 0)
		{ 
			break;
		}
		buffer[len] = '\0';
		printf("%s\n", buffer);
	}
*/
	close(rfd);
	
	return 0;
}
