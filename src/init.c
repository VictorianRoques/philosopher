/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:22:43 by viroques          #+#    #+#             */
/*   Updated: 2021/07/22 19:02:49 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_info(t_philo *philo, t_info *info, int i)
{
	philo->id = i + 1;
	philo->last_meal = 0;
	philo->round = 0;
	philo->info = info;
	philo->last_meal = get_time();
}

int	init_simulation(t_info *info)
{
	int		i;

	info->philos = malloc(sizeof(t_philo) * info->nb_philo);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
	if (!info->philos || !info->forks)
		return (1);
	i = 0;
	while (i < info->nb_philo)
	{
		if ((pthread_mutex_init(&info->forks[i], NULL)))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->m_log, NULL)
		|| pthread_mutex_init(&info->m_eat, NULL))
		return (1);
	info->h_zero = get_time();
	return (0);
}
