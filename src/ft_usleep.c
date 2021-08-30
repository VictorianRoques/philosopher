/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:40:23 by viroques          #+#    #+#             */
/*   Updated: 2021/08/30 11:32:33 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long int sleep)
{
	long long int	finish;

	finish = get_time() + sleep;
	while (get_time() < finish)
		usleep(sleep);
}
