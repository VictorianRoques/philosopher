/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:35:02 by viroques          #+#    #+#             */
/*   Updated: 2021/07/26 15:22:24 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	controler(t_info *info)
{	
	int			i;

	i = -1;
	while (++i < info->nb_philo)
	{
		init_philo_info(&info->philos[i], info, i);
		if (pthread_create(&info->philos[i].thread, NULL,
				(void *)routine, &info->philos[i]))
		{
			printf("pthread_create failed\n");
			return ;
		}
	}
	i = -1;
	while (++i < info->nb_philo)
	{
		if (pthread_join(info->philos[i].thread, NULL))
		{
			printf("pthread_join failed\n");
			return ;
		}
	}
}

int	main(int ac, char **argv)
{
	t_info		info;

	if (err_parsing(ac, argv, &info)
		|| init_simulation(&info))
		return (1);
	controler(&info);
	if (info.must_eat > -1 && !info.death)
		printf("End of simulation every philosopher eat %i times\n",
			info.must_eat);
	proper_exit(&info);
	return (0);
}
