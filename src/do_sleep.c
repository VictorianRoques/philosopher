/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:23:33 by viroques          #+#    #+#             */
/*   Updated: 2021/07/26 14:22:16 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	check_own(t_philo *philo)
{
	long long int	death;

	pthread_mutex_lock(&philo->info->m_eat);
	death = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->info->m_eat);
	pthread_mutex_lock(&philo->info->m_log);
	if (death > philo->info->time_to_die && !philo->info->death)
	{
		philo->info->death = 1;
		printf("%s%llu %d died %llu ms ago\n%s", RED,
			get_time_log(philo->info), philo->id,
			death - philo->info->time_to_die, NO_COLOR);
		pthread_mutex_unlock(&philo->info->m_log);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->m_log);
	return (0);
}

int	do_sleep(t_philo *philo, long long int duration)
{
	long long int	start_time;
	long long int	micro_nap;
	long long int	remaining_time;

	start_time = get_time();
	while (!check_own(philo))
	{
		remaining_time = (get_time() - start_time) * 1000;
		if (remaining_time >= duration)
			return (0);
		micro_nap = ft_min(5000, remaining_time);
		usleep(micro_nap);
	}
	return (1);
}
