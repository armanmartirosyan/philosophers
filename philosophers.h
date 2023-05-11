
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

// typedef struct	chopsticks {
// 	pthread_mutex_t	*mutex;
// 	size_t			seconds;
// 	size_t			milisec;
// }	t_chops;

typedef struct philo {
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		*threads;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}	t_philo;

// Utils
void	force_quit(void);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	*free_single(void **addr);
void	*free_double(void ***addr);

#endif