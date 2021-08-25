/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:40:23 by viroques          #+#    #+#             */
/*   Updated: 2021/08/25 17:44:34 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long int sleep)
{
	long long int	start;
	long long int	finish;
	long long int	before;

	finish = get_time() + sleep;
	start = get_time();
	while (start < finish)
	{
		before = get_time();
		usleep(sleep);
		start += get_time() - before;
	}
}
