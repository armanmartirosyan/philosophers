#include "philosophers.h"


void	philo_init(t_philo *philos, char **argv, int philo_num)
{
	int	i;

	i = -1;
	while (i++ < philo_num)
	{
		philos[i].id = i;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].threads = malloc (sizeof(pthread_t));
		if (!philos->threads)
			force_quit();
		pthread_mutex_init(&philos[i].mutex, NULL);
	}
	i = -1;
	while (i++ < philo_num)
	{
		if (i == 0)
		{
			philos[i].left = &philos[i + 1].mutex;
			philos[i].right = &philos[philo_num - 1].mutex;
		}
		else if (i + 1 == philo_num)
		{
			philos[i].left = &philos[i - 1].mutex;
			philos[i].right = &philos[0].mutex;
		}
		philos[i].left = &philos[i + 1].mutex;
		philos[i].right = &philos[i - 1].mutex;	
	}
}

void	*philo_start(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	pthread_mutex_lock(&philos->mutex);
	printf ("Bye from %d thread\n", philos->id);
	pthread_mutex_unlock(&philos->mutex);
	return (NULL);
}

int main(int argc, char **argv)
{
	t_philo    		 *philos;
	int				i;
	int				philo_num;
	int				num_of_times = ft_atoi(argv[5]);
	pthread_mutex_t	*forks;

	if (argc < 5 || argc > 6)
		return (write(1, "Wrong number of arguments!\n", 27) && 1);
	philo_num = ft_atoi(argv[1]);
	philos = (t_philo *)malloc(sizeof (t_philo) * philo_num);
	if (!philos)
		force_quit();
	philos = malloc (sizeof(t_philo) * philo_num);
	philo_init(philos, argv, philo_num);
	// printf ("Time to die: %d\n", philos[1].time_to_die);
	// printf ("Time to eat: %d\n", philos[2].time_to_eat);
	// printf ("Time to sleep: %d\n", philos[0].time_to_sleep);
	
	i = 0;
	while (i < philo_num)
	{
		printf ("Left: %p", philos[i])
	}

	// i = 0;
	// while (i < philo_num)
	// {
	// 	printf ("Hello from %d thread\n", philos[i].id);
	// 	pthread_create(philos[i].threads, NULL, philo_start, &philos[i]);
	// 	// system("read -p 'Press Enter to continue...'");
	// 	i++;
	// }

	// usleep(1000000);
	// system ("leaks philo");
	// printf ("Philo number: %d\n", philos->num_of_philo);
	// printf ("Time to die: %d\n", philos->time_to_die);
	// printf ("Time to eat: %d\n", philos->time_to_eat);
	// printf ("Time to sleep: %d\n", philos->time_to_sleep);
	// printf ("Number of times: %d\n", philos->num_of_times);

	

	return (0);
}