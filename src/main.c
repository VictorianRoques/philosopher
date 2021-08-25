/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:35:02 by viroques          #+#    #+#             */
/*   Updated: 2021/08/25 11:11:59 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(t_info *info)
{
	long long int	death;
	int				i;

	while (1)
	{
		i = -1;
		while (++i < info->nb_philo)
		{
			pthread_mutex_lock(&info->m_eat);
			death = get_time() - info->philos[i].last_meal;
			pthread_mutex_unlock(&info->m_eat);
			pthread_mutex_lock(&info->m_log);
			if (death >= info->time_to_die && !info->death)
			{
				info->death = 1;
				printf("%s%llu %d died\n%s", RED, get_time_log(info),
					info->philos[i].id, NO_COLOR);
				pthread_mutex_unlock(&info->m_log);
				usleep(500000);
				return (NULL);
			}
			pthread_mutex_unlock(&info->m_log);
		}
		usleep(5000);
	}
}

void	controler(t_info *info)
{	
	int			i;
	pthread_t	death;

	i = -1;
	while (++i < info->nb_philo)
	{
		init_philo_info(&info->philos[i], info, i);
		if (pthread_create(&info->philos[i].thread, NULL,
				(void *)routine, &info->philos[i]))
		{
			printf("pthread_create failed\n");
			return ;
		}
		if (pthread_detach(info->philos[i].thread))
			return ;
	}
	pthread_create(&death, NULL, (void *)check_death, info);
	pthread_join(death, NULL);
}

int	main(int ac, char **argv)
{
	t_info		info;

	if (err_parsing(ac, argv, &info)
		|| init_simulation(&info))
		return (1);
	controler(&info);
	if (info.must_eat > -1 && !info.death)
		printf("End of simulation every philosopher eat %i times\n",
			info.must_eat);
	proper_exit(&info);
	return (0);
}
