#include "philo.h"

void		thinking(t_philo *philo)
{
	printf("%s%llu %i is thinking\n", YELLOW, get_time_log(philo->info), philo->id);
	philo->status = THINKING;
}

void		sleeping(t_philo *philo)
{
	printf("%s%llu %i is sleeping\n", BLUE, get_time_log(philo->info), philo->id);
	usleep(philo->info->time_to_sleep * 1000);
	philo->status = SLEEPING;
}

void		eating(t_philo *philo)
{
	pthread_mutex_lock(philo->eating);
	philo->last_meal = get_time_log(philo->info);
	pthread_mutex_unlock(philo->eating);
	philo->round++;
	printf("%s%llu %i is eating\n", GREEN, get_time_log(philo->info), philo->id);
	usleep(philo->info->time_to_eat * 1000);
	philo->status = EATING;
}
