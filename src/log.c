/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:08:35 by viroques          #+#    #+#             */
/*   Updated: 2021/08/25 11:12:13 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log(t_philo *philo, char *doing, char *color)
{
	pthread_mutex_lock(&philo->info->m_log);
	if (philo->info->death || philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->m_log);
		return ;
	}
	if (doing)
	{
		printf("%s%llu%s %s%d %s%s%s\n", YELLOW, get_time_log(philo->info),
			NO_COLOR, BLUE, philo->id, color, doing, NO_COLOR);
	}
	pthread_mutex_unlock(&philo->info->m_log);
}
