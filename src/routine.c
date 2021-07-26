/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:54:44 by viroques          #+#    #+#             */
/*   Updated: 2021/07/26 15:50:59 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philo)
{
	if (ft_log(philo, SLEEPING, GREEN))
		return (1);
	if (do_sleep(philo, philo->info->time_to_sleep * 1000))
		return (1);
	return (0);
}

int	eating(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->info->m_eat);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->info->m_eat);
	if (philo->info->must_eat > -1)
	{
		philo->round++;
		if (philo->info->must_eat == philo->round)
			ret = 1;
	}
	ft_log(philo, EATING, PURPLE);
	usleep(philo->info->time_to_eat * 1000);
	return (ret);
}

int	delay_first_turn(t_philo *philo)
{
	if (philo->id % 2 == 0)
		if (do_sleep(philo, philo->info->time_to_eat * 1000))
			return (1);
	if (philo->info->nb_philo % 2
		&& philo->id == philo->info->nb_philo
		&& philo->id > 1)
		if (do_sleep(philo, philo->info->time_to_eat * 2000))
			return (1);
	if (philo->id == 1 && philo->info->nb_philo == 1)
	{
		ft_log(philo, FORK, GREEN);
		usleep(philo->info->time_to_die * 1000);
		philo->info->death = 1;
		printf("%s%llu 1 died\n%s", RED, get_time_log(philo->info), NO_COLOR);
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
		if (eating(philo))
		{
			release_forks(philo);
			return (NULL);
		}
		release_forks(philo);
		if (sleeping(philo))
			return (NULL);
		ft_log(philo, THINKING, GREEN);
		if (philo->info->nb_philo % 2)
			if (do_sleep(philo, philo->info->time_to_eat * 1000))
				return (NULL);
	}
	return (NULL);
}
