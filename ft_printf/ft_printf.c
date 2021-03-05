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

int	ft_nbrlen(int num)
{
	int length;

	if (num == 0)
		return (1);
	length = 0;
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return (length);
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

	if(!(result = malloc(sizeof(char) * (length - start) + 1)))
		return (NULL);
	i = 0;
	while (str[start] != '\0' && start < length)
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

int	ft_putnbr(int num)
{
	int ret;
	char ch;

	ret = 0;
	ch = '0';
	if (num / 10 > 0)
	{
		ret += ft_putnbr(num / 10);
	}
	ch += num % 10;
	ret += write(1, &ch, 1);
	return (ret);
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
	int pad;

	ret = 0;
	if (opt.prec == 0)
		str = ft_strdup("");
	else if (opt.prec > 0 && opt.prec <= ft_strlen(arg))
		str = ft_substr(arg, 0, opt.prec);
	else
		str = ft_strdup(arg);
	pad = opt.width - ft_strlen(str);
	while (pad-- > 0)
		ret += write(1, " ", 1);
	ret += write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

size_t	int_format(t_opt opt, int arg)
{
	int ret;
	int width;
	int prec;
	char *str;

	ret = 0;
	width = opt.width;
	prec = opt.prec;
	str = ft_strdup("");
	
	if (prec > ft_nbrlen(arg))
	{
		while (prec-- > ft_nbrlen(arg))
			str = ft_strjoin(ft_strdup("0"), str);
	}
		
	if (width > (ft_nbrlen(arg) + ft_strlen(str)))
	{
		while (width-- > (ft_nbrlen(arg) + ft_strlen(str)))
			str = ft_strjoin(ft_strdup(" "), str);
		printf("width : |%s|\n", str);
	}
	ret += write(1, str, ft_strlen(str));
	ret += ft_putnbr(arg);
	return (ret);
}
/*
size_t	hex_format(t_opt opt, unsigned int arg)
{
	int ret;

	ret = 0;

	return (ret);
}*/

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
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
				set_option(&opt, str[i++]);
			if (str[i] == 's' || str[i] == 'd' || str[i] == 'x')
			{
				opt.type = str[i];
				if (opt.type == 's')
					rtn += str_format(opt, va_arg(ap, char *));
				if (opt.type == 'd')
					rtn += int_format(opt, va_arg(ap, int));
				//if (opt.type == 'x')
				//	rtn += hex_format(opt, va_arg(ap, unsigned int));
			}
		}
		i++;
	}
	va_end(ap);
	return (rtn);
}
