#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			negativ;
	int			res;

	i = 0;
	negativ = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
		negativ = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * negativ);
}

long long int	ft_long_atoi(const char *nptr)
{
	int				i;
	int				negativ;
	long long int	res;

	i = 0;
	negativ = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
		negativ = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * negativ);
}

long long int	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (long long int)1000) + (tv.tv_usec / 1000));
}

long long int	get_time_log(t_info *info)
{
	return (get_time() - info->h_zero);
}

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while ((size_t)i < n)
	{
		str[i] = '\0';
		i++;
	}
}
