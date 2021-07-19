/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:23:06 by viroques          #+#    #+#             */
/*   Updated: 2021/07/19 16:23:27 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0 || (philo->info->nb_philo % 2 &&
		philo->id == philo->info->nb_philo))
		usleep(1000);
	pthread_mutex_lock(&philo->forks[philo->id - 1]);
	printf("%s%llu %i has taken a fork %i\n", WHITE, get_time_log(philo->info), philo->id, philo->id - 1);
	if (philo->id == philo->info->nb_philo)
	{
		pthread_mutex_lock(&philo->forks[0]);
		printf("%s%llu %i has taken a fork %i\n", WHITE, get_time_log(philo->info), philo->id, 0);
	}
	else
	{
		pthread_mutex_lock(&philo->forks[philo->id]);
		printf("%s%llu %i has taken a fork %i\n", WHITE, get_time_log(philo->info), philo->id, philo->id);
	}
	return (0);
}

int			release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->forks[philo->id - 1]);
	if (philo->id == philo->info->nb_philo)
		pthread_mutex_unlock(&philo->forks[0]);
	else
		pthread_mutex_unlock(&philo->forks[philo->id]);
	return (0);
}