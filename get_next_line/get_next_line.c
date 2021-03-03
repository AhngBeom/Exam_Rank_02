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

	if (!(result = malloc(sizeof(char) * (length - start))))
		return (NULL);
	while (i < length)
		result[i++] = str[start++];
	result[i] = '\0';
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

int	extract_line(char **line, char *str, int lf_idx)
{
	*line = ft_strdup(ft_substr(str, 0, lf_idx));
	str = ft_substr(str, lf_idx, ft_strlen(str));
	return (1);
}

int	get_next_line(char **line)
{
	static char	*stc_buff;
	char	buff[BUFF_SIZE];
	int	read_len;
	int	lf_idx;

	stc_buff = ft_strdup("");
	while ((read_len = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[read_len] = '\0';
		stc_buff = ft_strjoin(stc_buff, buff);
		if ((lf_idx = ft_strchr(stc_buff, '\n')) >= 0)
			return (extract_line(line, stc_buff, lf_idx));
	}

	return (0);
}
