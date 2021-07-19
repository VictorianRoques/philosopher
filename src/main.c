#include "philo.h"

int		controler(t_info *info)
{
	t_philo			*philos;
	pthread_mutex_t	*mutex;
	pthread_t		check;

	if (!(mutex = init_mutex_forks(info)))
		return (1);
	if (!(philos = launch_philosophe(info, mutex)))
		return (1);
	pthread_create(&check, NULL, (void *)check_death, philos);
	pthread_join(check, NULL);
	// i = - 1;
	// while (i++ < info->nb_philo)
	// 	pthread_mutex_destroy(&mutex[i]);
	return (0);
}

void	init_info(char **argv, t_info *info)
{
	info->h_zero = get_time();
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
}

int		main(int ac, char **argv)
{
	t_info	info;

	if (ac >= 5 && ac <= 6)
	{
		init_info(argv, &info);
		controler(&info);
	}
	return (0);
}