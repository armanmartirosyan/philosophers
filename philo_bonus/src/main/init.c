/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:53:35 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 20:03:19 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (philo_config(philos, argv))
		return (NULL);
	philos->die_flag = 0;
	sem_unlink(S_PHILO);
	sem_unlink(S_MSG);
	sem_unlink(S_DEAD);
	philos->philos_sem = NULL;
	philos->philos_sem = sem_open(S_PHILO, O_CREAT, 0755, philos->philo_num);
	philos->msg_sem = NULL;
	philos->msg_sem = sem_open(S_MSG, O_CREAT, 0755, 1);
	philos->dead_sem = NULL;
	philos->dead_sem = sem_open(S_DEAD, O_CREAT, 0755, 1);
	return (philos);
}
