/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:32:20 by viroques          #+#    #+#             */
/*   Updated: 2021/07/19 16:38:19 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		feed_philo(t_info *info, pthread_mutex_t *mutex, t_philo *philos, int i)
{
	philos[i].info = info;
	philos[i].id = i + 1;
	philos[i].last_meal = 0;
	philos[i].forks = mutex;
	philos[i].round = 0;
}

t_philo		*launch_philosophe(t_info *info, pthread_mutex_t *mutex)
{
	t_philo			*philos;
	int				i;

	i = 0;
	if (!(philos = malloc(sizeof(t_philo) * info->nb_philo)))
		return (NULL);
	while (i < info->nb_philo)
	{
		feed_philo(info, mutex, philos, i);
		if (init_mutex_eating(philos, i))
			return (NULL);
		if (pthread_create(&philos[i].thread, NULL, (void *)start_routine, &philos[i]))
		{
			printf("Pthread create failed\n");
			return (NULL);
		}
		pthread_detach(philos[i].thread);
		i++;
	}
	return (philos);
}