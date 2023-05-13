
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

# include "defines.h"

typedef struct philos {
	pthread_t		*threads;
	pthread_mutex_t	death;
	pthread_mutex_t	msg;
	int				hm_times;
	int				philo_num;
	int				die_flag;
	struct philo	*philo;
}	t_philos;

typedef struct philo {
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				last_meal;
	t_philos		*philos;
}	t_philo;

// Initialization
void		chopstick_config(t_philos *philos);
int			philo_config(t_philos *philos, char **argv);
t_philos	*philo_init(t_philos *philos, char **argv);

// Utils
int			ft_isdigit(int c);
int			force_quit(char *msg);
void		*fail_init(void);
int			ft_atoi(const char *str);
void		*free_single(void **addr);
void		*free_double(void ***addr);
void		ft_putstr_fd(char *s, int fd);

// Messeges
void	dead_msg(t_philos *philos, t_philo *philo, unsigned int time);
void	print_msg(t_philos *philos, t_philo *philo, char *msg);

// Time
unsigned int	ft_get_time(void);
void			ms_sleep(unsigned int time);

#endif