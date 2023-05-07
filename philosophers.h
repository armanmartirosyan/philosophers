
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct chopsticks {
	pthread_mutex_t	*mutex;
	size_t			seconds;
	size_t			milisec;
}	t_chops;

typedef struct philo {
	t_chops			*chops;
	pthread_t		*threads;
	int				id;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times;
}	t_philo;

// Utils
void	force_quit(void);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif