#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // read()
# include <fcntl.h> // open()
# include <stdlib.h> // malloc()
# include <stdio.h> // printf()

# define BUFF_SIZE 128
# define OPEN_MAX 3

int	get_next_line(char **line);

#endif
