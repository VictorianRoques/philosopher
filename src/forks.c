/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:22:46 by viroques          #+#    #+#             */
/*   Updated: 2021/07/26 16:11:49 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	release_forks(t_philo *philo)
{
	if (philo->id == philo->info->nb_philo)
	{
		pthread_mutex_unlock(&philo->info->forks[0]);
		ft_log(philo, FORK_DROP, GREEN);
		pthread_mutex_unlock(&philo->info->forks[philo->id - 1]);
		ft_log(philo, FORK_DROP, GREEN);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id - 1]);
		ft_log(philo, FORK_DROP, GREEN);
		pthread_mutex_unlock(&philo->info->forks[philo->id]);
		ft_log(philo, FORK_DROP, GREEN);
	}
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (philo->id == philo->info->nb_philo)
	{
		pthread_mutex_lock(&philo->info->forks[0]);
		ft_log(philo, FORK, GREEN);
		pthread_mutex_lock(&philo->info->forks[philo->id - 1]);
		ft_log(philo, FORK, GREEN);
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->id - 1]);
		ft_log(philo, FORK, GREEN);
		pthread_mutex_lock(&philo->info->forks[philo->id]);
		ft_log(philo, FORK, GREEN);
	}
	return (0);
}
