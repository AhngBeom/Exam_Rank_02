#include "get_next_line.h"

int	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (-1);
	while (*(str++) != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*mem;

	if (!(mem = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

int	ft_strchr(char *str, char ch)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == ch)
			return (idx);
		idx++;
	}
	return (-1);
}

char	*ft_substr(char *str, int start, int length)
{
	int	i;
	char *result;

	if (!str)
		return (NULL);
	if (!(result = malloc(sizeof(char) * (length - start) + 1)))
		return (NULL);
	i = 0;
	while (str[start] != '\0' && i < length)
		result[i++] = str[start++];
	result[i] = '\0';
	free(str);
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	if (!(result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

int	get_next_line(char **line)
{
	static char	*stc_buff;
	char	buff[BUFF_SIZE];
	char	*tmp;
	int	read_len;
	int	lf_idx;

	if (!stc_buff) 
		stc_buff = ft_strdup("");
	while ((read_len = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[read_len] = '\0';
		stc_buff = ft_strjoin(stc_buff, buff);
		printf("buff : %s", stc_buff);
		if ((lf_idx = ft_strchr(stc_buff, '\n')) >= 0)
		{
			tmp = ft_strdup(stc_buff);
			*line = ft_substr(stc_buff, 0, lf_idx);
			stc_buff = ft_substr(tmp, lf_idx + 1, ft_strlen(tmp));
			return (1);
		}
	}
	free(stc_buff);
	return (read_len);
}
