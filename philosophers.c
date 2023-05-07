#include "philosophers.h"


void	philo_init(t_philo *philos, char **argv)
{
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
}

void	*philo_start(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	// pthread_mutex_lock(philos->chops->mutex);
	printf ("Bye from %d thread\n", philos->id);
	// pthread_mutex_unlock(philos->chops->mutex);
	// usleep(100);
	return (NULL);
}

int main(int argc, char **argv)
{
	t_philo     **philos;
	pthread_t   *my_threads;
	int			i;
	int			philo_num;
	int			num_of_times = ft_atoi(argv[5]);
	pthread_mutex_t	forks;

	if (argc < 5 || argc > 6)
		return (write(1, "Wrong number of arguments!\n", 27));
	philo_num = ft_atoi(argv[1]);
	philos = (t_philo **)malloc(sizeof (t_philo *) * philo_num);
	if (!philos)
        force_quit();
	i = 0;
	while (i < philo_num)
	{
		philos[i] = malloc (sizeof(t_philo ));	
		philo_init(philos[i++], argv);
	}
	my_threads = malloc (sizeof(pthread_t) * philo_num);
	if (!my_threads)
		force_quit();
	i = 0;
	// pthread_mutex_init(&forks, NULL);
	while (i < philo_num)
	{
		philos[i]->id = i;
		printf ("Hello from %d thread\n", philos[i]->id);
		pthread_create(&my_threads[i], NULL, philo_start, philos[i]);
		// system("read -p 'Press Enter to continue...'");
		i++;
	}

// usleep(1000000);
	// pthread_join(my_threads[0], NULL);
	// pthread_join(my_threads[1], NULL);
	// pthread_join(my_threads[2], NULL);
	// pthread_join(my_threads[3], NULL);
	// pthread_join(my_threads[4], NULL);
	// printf ("Philo number: %d\n", philos->num_of_philo);
	// printf ("Time to die: %d\n", philos->time_to_die);
	// printf ("Time to eat: %d\n", philos->time_to_eat);
	// printf ("Time to sleep: %d\n", philos->time_to_sleep);
	// printf ("Number of times: %d\n", philos->num_of_times);

	

	return (0);
}