/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:06:40 by viroques          #+#    #+#             */
/*   Updated: 2021/07/22 18:59:48 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end_rounds(t_info *info)
{
	pthread_mutex_lock(&info->m_eat);
	if (info->finish)
	{
		printf("%sEND OF SIMULATION EVERY PHILO EAT %i times\n%s", RED,
			info->must_eat, NO_COLOR);
		pthread_mutex_unlock(&info->m_eat);
		return (1);
	}
	pthread_mutex_unlock(&info->m_eat);
	return (0);
}

int	check_death(t_info *info)
{
	int				i;
	long long int	death;

	i = -1;
	while (++i < info->nb_philo)
	{
		pthread_mutex_lock(&info->m_eat);
		death = get_time() - info->philos->last_meal;
		pthread_mutex_unlock(&info->m_eat);
		if (death > info->time_to_die)
		{
			pthread_mutex_lock(&info->m_log);
			info->death = 1;
			printf("%s%llu %d died %llu ms ago\n%s", RED,
				get_time_log(info), i + 1,
				death - info->time_to_die, NO_COLOR);
			pthread_mutex_unlock(&info->m_log);
			return (1);
		}
	}
	return (0);
}

void	*check_end_simulation(t_info *info)
{
	while (1)
	{
		if (check_end_rounds(info) || check_death(info))
			return (NULL);
		usleep(5000);
	}
}
