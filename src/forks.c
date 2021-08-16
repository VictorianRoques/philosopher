/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:22:46 by viroques          #+#    #+#             */
/*   Updated: 2021/08/16 13:07:01 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->id - 1]);
	ft_log(philo, FORK_DROP, GREEN);
	if (philo->id == philo->info->nb_philo)
		pthread_mutex_unlock(&philo->info->forks[0]);
	else
		pthread_mutex_unlock(&philo->info->forks[philo->id]);
	ft_log(philo, FORK_DROP, GREEN);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->id - 1]);
	ft_log(philo, FORK, GREEN);
	if (philo->id == philo->info->nb_philo)
		pthread_mutex_lock(&philo->info->forks[0]);
	else
		pthread_mutex_lock(&philo->info->forks[philo->id]);
	ft_log(philo, FORK, GREEN);
}
