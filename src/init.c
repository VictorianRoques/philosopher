/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:37:14 by viroques          #+#    #+#             */
/*   Updated: 2021/07/19 16:38:16 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t		*init_mutex_forks(t_info *info)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	if (!(mutex = malloc(sizeof(pthread_mutex_t) * info->nb_philo)))
		return (NULL);
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&mutex[i], NULL))
		{
			printf("Mutex init failed \n");
			return (NULL);
		}
		i++;
	}
	return (mutex);
}

int			init_mutex_eating(t_philo *philos, int i)
{
	if (!(philos[i].eating = malloc(sizeof(pthread_mutex_t))))
		return (1);
	if (pthread_mutex_init(philos[i].eating, NULL))
	{
		printf("Mutex init failed \n");
		return (1);
	}
	return (0);
}