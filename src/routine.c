/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:54:44 by viroques          #+#    #+#             */
/*   Updated: 2021/07/27 20:01:28 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	ft_log(philo, SLEEPING, GREEN);
	do_sleep(philo, philo->info->time_to_sleep * 1000);
}

void	eating(t_philo *philo)
{	
	pthread_mutex_lock(&philo->info->m_eat);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->info->m_eat);
	if (philo->info->must_eat > -1)
		philo->round++;
	ft_log(philo, EATING, PURPLE);
	usleep(philo->info->time_to_eat * 1000);
}

void	delay_first_turn(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 500);
	if (philo->info->nb_philo % 2 > 0
		&& philo->id == philo->info->nb_philo
		&& philo->id > 1)
		usleep(philo->info->time_to_eat * 1000 + 50);
	if (philo->id == 1 && philo->info->nb_philo == 1)
	{
		ft_log(philo, FORK, GREEN);
		usleep(philo->info->time_to_die * 1000);
		philo->info->death = 1;
		printf("%s%llu 1 died\n%s", RED, get_time_log(philo->info), NO_COLOR);
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
	return (NULL);
}
