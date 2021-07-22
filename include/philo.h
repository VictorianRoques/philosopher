#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>

# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define LEFT_FORK "has taken a fork"
# define RIGHT_FORK "has taken a fork"
# define LEFT_FORK_DROP "has dropped a fork"
# define RIGHT_FORK_DROP "has dropped a fork"

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define NO_COLOR "\033[0;37m"

typedef struct s_info
{
	int					nb_philo;
	long long int		time_to_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	int					must_eat;
	long long int		h_zero;
	int					death;
	int					finish;
	struct s_philo		*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		m_log;
	pthread_mutex_t		m_eat;
}						t_info;

typedef struct s_philo
{
	int					id;
	long long int		last_meal;
	pthread_t			thread;
	int					round;
	t_info				*info;
}						t_philo;

int						ft_atoi(const char *nptr);
long long int			ft_long_atoi(const char *nptr);
long long int			get_time(void);
long long int			get_time_log(t_info *info);
void					ft_bzero(void *s, size_t n);
int						err_parsing(int ac, char **argv, t_info *info);
int						init_simulation(t_info *info);
void					init_philo_info(t_philo *philo, t_info *info, int i);
void					proper_exit(t_info *info);
int						ft_log(t_philo *philo, char *doing, char *color);
int						take_forks(t_philo *philo);
int						release_forks(t_philo *philo);
void					*routine(t_philo *philo);
void					*check_end_simulation(t_info *info);

#endif
