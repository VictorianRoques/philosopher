/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:54:44 by viroques          #+#    #+#             */
/*   Updated: 2021/09/03 11:25:26 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	ft_log(philo, SLEEPING, GREEN);
	ft_usleep(philo->info->time_to_sleep);
}

void	eating(t_philo *philo)
{	
	pthread_mutex_lock(&philo->info->m_eat);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->info->m_eat);
	ft_log(philo, EATING, PURPLE);
	if (philo->info->must_eat > -1)
		philo->round++;
	if (philo->round == philo->info->must_eat)
	{
		pthread_mutex_lock(&philo->info->m_log);
		philo->info->finish++;
		pthread_mutex_unlock(&philo->info->m_log);
	}
	ft_usleep(philo->info->time_to_eat);
}

void	delay_first_turn(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(10);
	if (philo->info->nb_philo % 2 > 0
		&& philo->id == philo->info->nb_philo
		&& philo->id > 1)
		ft_usleep(20);
	if (philo->id == 1 && philo->info->nb_philo == 1)
	{
		ft_log(philo, FORK, GREEN);
		ft_usleep(philo->info->time_to_die);
		philo->info->death = 1;
	}
}

void	*routine(t_philo *philo)
{
	delay_first_turn(philo);
	pthread_mutex_lock(&philo->info->m_log);
	while (!philo->info->death && philo->info->finish != philo->info->nb_philo)
	{
		pthread_mutex_unlock(&philo->info->m_log);
		take_forks(philo);
		eating(philo);
		release_forks(philo);
		sleeping(philo);
		ft_log(philo, THINKING, GREEN);
	}
	pthread_mutex_unlock(&philo->info->m_log);
	return (NULL);
}
