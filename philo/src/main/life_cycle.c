/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:54:15 by armartir          #+#    #+#             */
/*   Updated: 2023/05/14 13:30:44 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philos *philos, t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(&philos->death);
	time = ft_get_time();
	if (time - philo->last_meal > (unsigned int)(philo->time_to_die + 10))
	{
		add_dead(philos);
		dead_msg(philos, philo, time);
	}
	pthread_mutex_unlock(&philos->death);
	return (0);
}

void	philo_sleep(t_philos *philos, t_philo *philo)
{
	pthread_mutex_lock(&philos->death);
	print_msg(philos, philo, P_SLEEP, 0);
	pthread_mutex_unlock(&philos->death);
	ms_sleep(philo->time_to_sleep);
	pthread_mutex_lock(&philos->death);
	print_msg(philos, philo, P_THINK, 0);
	pthread_mutex_unlock(&philos->death);
}

int	philo_life(t_philos *philos, t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(&philos->death);
	print_msg(philos, philo, P_TFORK, 0);
	pthread_mutex_unlock(&philos->death);
	is_dead(philos, philo);
	pthread_mutex_lock(&philos->death);
	philo->last_meal = print_msg(philos, philo, P_EAT, 1);
	pthread_mutex_unlock(&philos->death);
	ms_sleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (philo->times == philos->hm_times)
		return (EXIT_FAILURE);
	philo_sleep(philos, philo);
	return (EXIT_SUCCESS);
}

void	one_philo(t_philos *philos, t_philo *philo)
{
	print_msg(philos, philo, P_TFORK, 0);
	ms_sleep(philo->time_to_die);
	add_dead(philos);
	dead_msg(philos, philo, ft_get_time());
}

void	*start_matrix(void *arg)
{
	t_philo		*philo;
	t_philos	*philos;

	philo = (t_philo *)arg;
	philos = philo->philos;
	if (philos->philo_num == 1)
	{
		one_philo(philos, philo);
		return (NULL);
	}
	if (philo->id % 2)
		ms_sleep(philos->philo->time_to_eat);
	while (1)
	{
		if (philo_life(philos, philo))
			return (NULL);
		pthread_mutex_lock(&philos->death);
		if (philos->die_flag != 0)
		{
			pthread_mutex_unlock(&philos->death);
			return (NULL);
		}
		pthread_mutex_unlock(&philos->death);
	}
	return (NULL);
}
