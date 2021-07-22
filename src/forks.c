/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:22:46 by viroques          #+#    #+#             */
/*   Updated: 2021/07/22 19:03:26 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->id - 1]);
	ft_log(philo, RIGHT_FORK_DROP, GREEN);
	if (philo->id == philo->info->nb_philo)
		pthread_mutex_unlock(&philo->info->forks[0]);
	else
		pthread_mutex_unlock(&philo->info->forks[philo->id]);
	ft_log(philo, LEFT_FORK_DROP, GREEN);
	return (0);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->id - 1]);
	ft_log(philo, RIGHT_FORK, GREEN);
	if (philo->id == philo->info->nb_philo)
		pthread_mutex_lock(&philo->info->forks[0]);
	else
		pthread_mutex_lock(&philo->info->forks[philo->id]);
	ft_log(philo, LEFT_FORK, GREEN);
	return (0);
}
