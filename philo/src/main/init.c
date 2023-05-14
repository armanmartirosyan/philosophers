/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:53:35 by armartir          #+#    #+#             */
/*   Updated: 2023/05/14 12:57:48 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	chopstick_config(t_philos *philos)
{
	int	i;

	i = 0;
	philos->philo[i].left = &philos->philo[i].mutex;
	philos->philo[i].right = &philos->philo[philos->philo_num - 1].mutex;
	while (++i < philos->philo_num)
	{
		philos->philo[i].left = &philos->philo[i].mutex;
		philos->philo[i].right = &philos->philo[i - 1].mutex;
	}
	philos->philo[i].left = &philos->philo[0].mutex;
	philos->philo[i].right = &philos->philo[i].mutex;
}

int	philo_config(t_philos *philos, char **argv)
{
	int	i;

	i = -1;
	while (++i < philos->philo_num)
	{
		philos->philo[i].id = i;
		philos->philo[i].time_to_die = ft_atoi(argv[2]);
		philos->philo[i].time_to_eat = ft_atoi(argv[3]);
		philos->philo[i].time_to_sleep = ft_atoi(argv[4]);
		philos->philo[i].last_meal = 0;
		philos->philo[i].philos = philos;
		philos->philo[i].times = 0;
		if (pthread_mutex_init(&philos->philo[i].mutex, NULL) == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_philos	*philo_init(t_philos *philos, char **argv)
{
	philos = (t_philos *)malloc(sizeof (t_philos));
	if (!philos)
		return (fail_init());
	philos->philo_num = ft_atoi(argv[1]);
	if (!argv[5])
		philos->hm_times = -1;
	else
		philos->hm_times = ft_atoi(argv[5]);
	philos->philo = (t_philo *)malloc(sizeof(t_philo) * philos->philo_num);
	if (!philos->philo)
		return (fail_init());
	philos->threads = malloc (sizeof(pthread_t) * philos->philo_num);
	if (!philos->threads)
		return (fail_init());
	if (philo_config(philos, argv))
		return (NULL);
	philos->die_flag = 0;
	chopstick_config(philos);
	if (pthread_mutex_init(&philos->death, NULL) == -1
		|| pthread_mutex_init(&philos->msg, NULL) == -1
		|| pthread_mutex_init(&philos->death_flag, NULL) == -1)
		return (NULL);
	return (philos);
}
