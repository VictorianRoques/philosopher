/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:31:29 by viroques          #+#    #+#             */
/*   Updated: 2021/07/19 16:31:51 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*check_death(t_philo *philos)
{
	int			i;
	uint64_t	dead;

	while (1)
	{
		i = 0;
		while (i < philos->info->nb_philo)
		{
			dead = get_time_log(philos->info) - philos[i].last_meal;
			if (dead > philos->info->time_to_die)
			{
				printf("%s%llu %i is dead\n", RED, get_time_log(philos->info), philos[i].id);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}