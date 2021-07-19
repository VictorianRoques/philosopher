#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DEAD 3

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define NO_COLOR "\033[0;37m"

typedef struct		s_info
{
	int				nb_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		h_zero;
	int				must_eat;
}					t_info;

typedef struct		s_philo
{
	int				id;
	uint64_t		last_meal;
	pthread_t		thread;
	int				status;
	int				round;
	t_info			*info;
	pthread_mutex_t	*forks;
	pthread_mutex_t *eating;
}					t_philo;

int					ft_atoi(const char *nptr);
uint64_t			get_time(void);
uint64_t			get_time_log(t_info *info);
void				take_fork(t_philo *philo);
void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
void				eating(t_philo *philo);
void				status_take_fork(t_philo *philo);
int					take_forks(t_philo *philo);
int					release_forks(t_philo *philo);
void				*start_routine(t_philo *philo);
void				*check_death(t_philo *philos);
t_philo				*launch_philosophe(t_info *info, pthread_mutex_t *mutex);
pthread_mutex_t		*init_mutex_forks(t_info *info);
int					init_mutex_eating(t_philo *philos, int i);
#endif