/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:54:44 by viroques          #+#    #+#             */
/*   Updated: 2021/08/25 17:37:42 by viroques         ###   ########.fr       */
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
	if (philo->info->must_eat > -1)
		philo->round++;
	ft_log(philo, EATING, PURPLE);
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
	while (philo->round != philo->info->must_eat && !philo->info->death)
	{
		take_forks(philo);
		eating(philo);
		release_forks(philo);
		sleeping(philo);
		ft_log(philo, THINKING, GREEN);
	}
	if (!philo->info->finish && philo->round == philo->info->must_eat)
		philo->info->finish = 1;
	return (NULL);
}
