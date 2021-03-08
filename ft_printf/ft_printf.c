#include <unistd.h> // write()
#include <stdlib.h> // malloc()
#include <stdarg.h> // va_list, va_start(), va_arg(), va_end()
#include <stdio.h> // printf()

typedef struct s_opt{
	int width;
	int prec;
	char type;
} t_opt;

int	ft_strlen(char *str)
{
	int count;

	if (str == NULL)
		return (-1);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	int i;
	char *mem;

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

char	*ft_substr(char *str, int start, int length)
{
	int i;
	char *result;

	if(!(result = malloc(sizeof(char) * length + 1)))
		return (NULL);
	i = 0;
	while (str[start] != '\0' && i < length)
		result[i++] = str[start++];
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *result;

	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
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
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	free(s2);
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(long long num, char *base)
{
	char *result;

	if (num < 0)
		num *= -1;
	if (num / ft_strlen(base) > 0)
		result = ft_itoa(num / ft_strlen(base), base);
	else
		result = ft_strdup("");
	result = ft_strjoin(result, ft_substr(base, num % ft_strlen(base), 1));
	return (result);
}

t_opt	init_option()
{
	t_opt opt;

	opt.width = 0;
	opt.prec = -1;
	opt.type = 0;
	return (opt);
}

void	set_option(t_opt *opt, char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		if (opt->prec == -1)
			opt->width = (opt->width * 10) + ch - 48;
		else
			opt->prec = (opt->prec * 10) + ch - 48;
	}
	else if (ch == '.')
		opt->prec = 0;
	else 
		return ;
}

size_t	str_format(t_opt opt, char *arg)
{
	int ret;
	char *str;

	if (opt.prec == 0)
		str = ft_strdup("");
	else if (arg == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(arg);
	if (opt.prec > 0 && opt.prec < ft_strlen(str))
		str = ft_substr(str, 0, opt.prec);
	if (opt.width > ft_strlen(str))
	{
		while (opt.width != ft_strlen(str))
			str = ft_strjoin(ft_strdup(" "), str);
	}
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

size_t	int_format(t_opt opt, int arg)
{
	int ret;
	char *sign;
	char *str;

	sign = ft_strdup("");
	if (opt.prec == 0)
		str = ft_strdup("");
	else	
	{
 		if (arg < 0)
			sign = ft_strjoin(sign, ft_strdup("-"));
		str = ft_itoa(arg, "0123456789");
	}
	if (opt.prec > ft_strlen(str))
	{
		while (ft_strlen(str) != opt.prec)
			str = ft_strjoin(ft_strdup("0"), str);
	}
	str = ft_strjoin(sign, str);
	if (opt.width > (ft_strlen(str)))
	{
		while (ft_strlen(str) != opt.width)
			str = ft_strjoin(ft_strdup(" "), str);
	}
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

size_t	hex_format(t_opt opt, unsigned int arg)
{
	int ret;
	char *str;

	str = ft_itoa(arg, "0123456789abcdef");
	if (opt.prec > ft_strlen(str))
	{
		while (ft_strlen(str) != opt.prec)
			str = ft_strjoin(ft_strdup("0"), str);
	}

	if (opt.width > ft_strlen(str))
	{
		while (ft_strlen(str) != opt.width)
			str = ft_strjoin(ft_strdup(" "), str);
	}
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

int ft_printf(const char *str, ...)
{
	int i;
	size_t rtn;
	t_opt opt;
	va_list ap;

	va_start(ap, str);
	rtn = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			rtn += write(1, &str[i], 1);
		else
		{
			i++;
			opt = init_option();
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '-')
				set_option(&opt, str[i++]);
			if (str[i] == 's' || str[i] == 'd' || str[i] == 'x')
			{
				opt.type = str[i];
				if (opt.type == 's')
					rtn += str_format(opt, va_arg(ap, char *));
				if (opt.type == 'd')
					rtn += int_format(opt, va_arg(ap, int));
				if (opt.type == 'x')
					rtn += hex_format(opt, va_arg(ap, unsigned int));
			}
			else
				return (rtn);
		}
		i++;
	}
	va_end(ap);
	return (rtn);
}
