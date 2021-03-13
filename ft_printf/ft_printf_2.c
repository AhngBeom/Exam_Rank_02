#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_opt
{
	int	width;
	int	prec;
	char	type;
}	t_opt;

static	void	set_opt(t_opt *opt, char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		if (opt->prec == -1)
			opt->width = opt->width * 10 + (ch - 48);
		else
			opt->prec = opt->prec * 10 + (ch - 48);
	}
	else if (ch == '.')
		opt->prec = 0;
	else
		return ;
}

static	int	ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static	char	*ft_strdup(char *str)
{
	char	*result;
	int	i;

	if (str == NULL)
		return (NULL);
	if (!(result = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static	char	*ft_substr(char *str, int start, int length)
{
	char	*result;
	int	i;

	if (!str)
		return (NULL);
	if (!(result = malloc(sizeof(char) * length + 1)))
		return (NULL);

	i = 0;
	while (i < length && str[start] != '\0')
		result[i++] = str[start++];
	free(str);
	result[i] = '\0';
	return (result);
}

static	char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int	i;
	int	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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
	free(s2);
	result[i] = '\0';
	return (result);
}

static	char	*ft_itoa(long long num, char *base)
{
	char	*result;
	int	base_len;

	if (num < 0)
		num *= -1;

	base_len = ft_strlen(base);
	if (num / base_len > 0)
	{
		result = ft_strjoin(ft_itoa(num / base_len, base), ft_substr(ft_strdup(base), num % base_len, 1));
	}
	else
		result = ft_substr(ft_strdup(base), num % base_len, 1);
	return (result);
}

static	int	str_format(t_opt opt, char *str)
{
	char	*result;
	int	ret;

	if (opt.prec == 0)
		str = "";
	else if (!str)
		str = "(null)";

	result = ft_strdup(str);

	if (opt.prec > 0 && opt.prec < ft_strlen(result))
	{
		result = ft_substr(result, 0, opt.prec);
	}
	if (opt.width > 0 && opt.width > ft_strlen(result))
	{
		while (opt.width != ft_strlen(result))
			result = ft_strjoin(ft_strdup(" "), result); 
	}
	ret = write(1, result, ft_strlen(result));
	free(result);
	return (ret);
}

static	int	int_format(t_opt opt, int num)
{
	char	*result;
	char	*sign;
	int	ret;

	sign = ft_strdup("");
	if (opt.prec == 0 && num == 0)
		result = ft_strdup("");
	else
	{
		if (num < 0)
			sign = ft_strjoin(sign, ft_strdup("-"));
		result = ft_itoa(num, "0123456789");
	}
	if (opt.prec > 0 && opt.prec > ft_strlen(result))
	{
		while (opt.prec != ft_strlen(result))
			result = ft_strjoin(ft_strdup("0"), result);
	}
	result = ft_strjoin(sign, result);
	if (opt.width > 0 && opt.width > ft_strlen(result))
	{
		while (opt.width != ft_strlen(result))
			result = ft_strjoin(ft_strdup(" "), result);
	}
	ret = write(1, result, ft_strlen(result));
	free(result);
	return (ret);
}

static	int	hex_format(t_opt opt, unsigned int num)
{
	char	*result;
	int	ret;

	if (opt.prec == 0 && num == 0)
		result = ft_strdup("");
	else
		result = ft_itoa(num, "0123456789abcdef");
	if (opt.prec > 0 && opt.prec > ft_strlen(result))
	{
		while (opt.prec != ft_strlen(result))
			result = ft_strjoin(ft_strdup("0"), result);
	}
	if (opt.width > 0 && opt.width > ft_strlen(result))
	{
		while (opt.width != ft_strlen(result))
			result = ft_strjoin(ft_strdup(" "), result);
	}
	ret = write(1, result, ft_strlen(result));
	free(result);
	return (ret);

}

static	int	output(t_opt opt, va_list ap)
{
	int	ret;

	ret = 0;
	if (opt.type == 's')
		ret += str_format(opt, va_arg(ap, char *));
	else if (opt.type == 'd')
		ret += int_format(opt, va_arg(ap, int));
	else if (opt.type == 'x')
		ret += hex_format(opt, va_arg(ap, unsigned int));
	else
		ret += 0;
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_opt	opt;
	int	ret;
	int	i;

	va_start(ap, str);
	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ret += write(1, &str[i++], 1);
		else
		{
			++i;
			opt.width = 0;
			opt.prec = -1;
			opt.type = '\0';
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '-')
				set_opt(&opt, str[i++]);
			if (str[i] == 's' || str[i] == 'd' || str[i] == 'x')
			{
				opt.type = str[i++];
				ret += output(opt, ap);
			}
		}
	}
	va_end(ap);
	return (ret);
}

