/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:56:43 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 20:26:34 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*wait_eat(void *arg)
{
	int			i;
	t_philos	*philos;

	i = 0;
	philos = (t_philos *)arg;
	while (i < (int)philos->philo_num)
	{
		waitpid(philos->philo[i].pid, NULL, 0);
		i++;
	}
	sem_post(philos->dead_sem);
	return (NULL);
}

void	wait_philos(t_philos *philos)
{
	pthread_t	*thread;
	int			i;

	thread = (pthread_t *)malloc(sizeof(pthread_t));
	sem_wait(philos->dead_sem);
	if (pthread_create(thread, NULL, &wait_eat, (void *)philos))
		force_quit(E_CTHREAD);
	sem_wait(philos->dead_sem);
	if (pthread_detach(*thread))
		force_quit(E_PDETACH);
	free_single((void *)&thread);
	i = 0;
	while (i < (int)philos->philo_num)
	{
		kill(philos->philo[i].pid, SIGTERM);
		i++;
	}
}

int	philo_start(t_philos *philos)
{
	int		i;

	i = 0;
	ft_get_time();
	while (i < philos->philo_num)
	{
		philos->philo[i].pid = fork();
		if (philos->philo[i].pid < 0)
			return (force_quit(E_FORK));
		if (philos->philo[i].pid == 0)
		{
			if (i % 2)
				usleep(philos->philo[i].time_to_eat);
			start_matrix(philos, &philos->philo[i]);
			exit(0);
		}
		i++;
	}
	wait_philos(philos);
	free_all(philos);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philos	*philos;

	if (argc < 5 || argc > 6)
		return (force_quit(E_ARGNUM));
	if (check_args(argv, argc))
		return (force_quit(E_NEGNUM));
	philos = NULL;
	philos = philo_init(philos, argv);
	if (!philos)
		return (EXIT_FAILURE);
	if (philo_start(philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
