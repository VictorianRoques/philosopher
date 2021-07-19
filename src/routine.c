/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:29:57 by viroques          #+#    #+#             */
/*   Updated: 2021/07/19 16:30:15 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*start_routine(t_philo *philo)
{
	while (1)
	{
		take_forks(philo);
		eating(philo);
		release_forks(philo);
		if (philo->round == philo->info->must_eat
			&& philo->info->must_eat > -1)
				break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}