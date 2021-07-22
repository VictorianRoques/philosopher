/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:54:44 by viroques          #+#    #+#             */
/*   Updated: 2021/07/22 19:07:03 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philo)
{
	if (ft_log(philo, SLEEPING, GREEN))
		return (1);
	usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_eat);
	philo->last_meal = get_time();
	if (philo->info->must_eat)
		philo->round++;
	pthread_mutex_unlock(&philo->info->m_eat);
	ft_log(philo, EATING, PURPLE);
	usleep(philo->info->time_to_eat * 1000);
	return (0);
}

int	check_if_has_finish(t_philo *philo)
{
	if (philo->info->must_eat > -1
		&& philo->round == philo->info->must_eat)
	{
		pthread_mutex_lock(&philo->info->m_eat);
		philo->info->finish = 1;
		pthread_mutex_unlock(&philo->info->m_eat);
		return (1);
	}
	return (0);
}

int	delay_first_turn(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	if (philo->info->nb_philo % 2
		&& philo->id == philo->info->nb_philo
		&& philo->id > 1)
		usleep(philo->info->time_to_eat * 2000);
	if (philo->id == 1 && philo->info->nb_philo == 1)
	{
		pthread_mutex_lock(&philo->info->forks[0]);
		ft_log(philo, RIGHT_FORK, GREEN);
		usleep(philo->info->time_to_die * 1000);
		pthread_mutex_unlock(&philo->info->forks[0]);
		return (1);
	}
	return (0);
}

void	*routine(t_philo *philo)
{
	if (delay_first_turn(philo))
		return (NULL);
	while (1)
	{
		take_forks(philo);
		eating(philo);
		release_forks(philo);
		check_if_has_finish(philo);
		if (sleeping(philo) || ft_log(philo, THINKING, GREEN))
			return (NULL);
		if (philo->info->nb_philo % 2)
			usleep(philo->info->time_to_eat * 1000);
	}
	return (NULL);
}
