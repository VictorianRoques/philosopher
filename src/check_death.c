/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:12:48 by viroques          #+#    #+#             */
/*   Updated: 2021/09/03 14:37:41 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_finish(t_info *info)
{
	pthread_mutex_lock(&info->m_log);
	if (info->finish == info->nb_philo)
	{
		pthread_mutex_unlock(&info->m_log);
		return (1);
	}
	pthread_mutex_unlock(&info->m_log);
	return (0);
}

void	*check_death(t_info *info)
{
	long long int	death;
	int				i;

	while (!is_finish(info))
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
				return (NULL);
			}
			pthread_mutex_unlock(&info->m_log);
		}
		ft_usleep(1);
	}
	return (NULL);
}
