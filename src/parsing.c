/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:11:01 by viroques          #+#    #+#             */
/*   Updated: 2021/08/30 11:56:04 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	only_number(int ac, char **argv)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_number(argv[i]))
		{
			printf("Only number are allowed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_values(t_info *info, int ac, char **argv)
{
	info->nb_philo = ft_atoi(argv[1]);
	if (!info->nb_philo)
	{
		printf("Need at least one philo\n");
		return (1);
	}
	info->time_to_die = ft_long_atoi(argv[2]);
	info->time_to_eat = ft_long_atoi (argv[3]);
	info->time_to_sleep = ft_long_atoi(argv[4]);
	if (ac == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (!info->must_eat)
		{
			printf("End of simulation every philosopher eat 0 times\n");
			return (1);
		}
	}
	else
		info->must_eat = -1;
	return (0);
}

int	err_parsing(int ac, char **argv, t_info *info)
{
	if (ac >= 5 && ac <= 6)
	{
		ft_bzero(info, sizeof(t_info));
		if (only_number(ac, argv) || get_values(info, ac, argv))
			return (1);
	}
	else
	{
		printf("Wrong number of arguments \n");
		return (1);
	}
	return (0);
}
