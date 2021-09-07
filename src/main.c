/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:35:02 by viroques          #+#    #+#             */
/*   Updated: 2021/09/03 14:12:58 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	controler(t_info *info)
{	
	int			i;
	pthread_t	death;

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
		if (pthread_detach(info->philos[i].thread))
			return ;
	}
	if (pthread_create(&death, NULL, (void *)check_death, info)
		|| pthread_join(death, NULL))
		return ;
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
