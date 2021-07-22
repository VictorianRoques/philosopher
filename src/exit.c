/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:44:40 by viroques          #+#    #+#             */
/*   Updated: 2021/07/22 19:03:08 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	proper_exit(t_info *info)
{
	int		i;

	pthread_mutex_lock(&info->m_eat);
	if (info->philos)
		free(info->philos);
	pthread_mutex_unlock(&info->m_eat);
	pthread_mutex_destroy(&info->m_eat);
	pthread_mutex_destroy(&info->m_log);
	if (info->forks)
	{
		i = 0;
		while (i < info->nb_philo)
		{
			pthread_mutex_destroy(&info->forks[i]);
			i++;
		}
		free(info->forks);
	}
}
