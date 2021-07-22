/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:35:02 by viroques          #+#    #+#             */
/*   Updated: 2021/07/22 19:08:45 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	controler(t_info *info)
{	
	int			i;
	pthread_t	check;

	i = -1;
	while (++i < info->nb_philo)
	{
		init_philo_info(&info->philos[i], info, i);
		if (pthread_create(&info->philos[i].thread, NULL,
				(void *)routine, &info->philos[i]))
		{
			printf("pthread_create failed \n");
			return ;
		}
		pthread_detach(info->philos[i].thread);
	}
	usleep(100);
	pthread_create(&check, NULL, (void *)check_end_simulation, info);
	pthread_join(check, NULL);
}

int	main(int ac, char **argv)
{
	t_info		info;

	if (err_parsing(ac, argv, &info)
		|| init_simulation(&info))
		return (1);
	controler(&info);
	usleep(1000000);
	proper_exit(&info);
	return (0);
}
