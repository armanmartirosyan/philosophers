/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:54:15 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 21:01:08 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philos *philos, t_philo *philo)
{
	unsigned int	i;

	i = ft_get_time();
	if ((i - philo->last_meal) > (unsigned int)philo->time_to_die)
	{
		philos->die_flag = 1;
		dead_msg(philos, philo, i);
	}
	return (philos->die_flag);
}

void	philo_sleep(t_philos *philos, t_philo *philo)
{
	print_msg(philos, philo, P_SLEEP, 0);
	ms_sleep(philo->time_to_sleep);
	print_msg(philos, philo, P_THINK, 0);
}

void	philo_life(t_philos *philos, t_philo *philo)
{
	sem_wait(philos->philos_sem);
	sem_wait(philos->philos_sem);
	print_msg(philos, philo, P_TFORK, 0);
	if (is_dead(philos, philo))
		return ;
	philo->last_meal = print_msg(philos, philo, P_EAT, 1);
	ms_sleep(philo->time_to_eat);
	sem_post(philos->philos_sem);
	sem_post(philos->philos_sem);
	if (philo->times == philos->hm_times)
		exit (1);
	philo_sleep(philos, philo);
}

void	one_philo(t_philos *philos, t_philo *philo)
{
	print_msg(philos, philo, P_TFORK, 0);
	ms_sleep(philo->time_to_die);
	add_dead(philos);
	dead_msg(philos, philo, ft_get_time());
}

void	*start_matrix(t_philos *philos, t_philo *philo)
{
	if (philos->philo_num == 1)
	{
		one_philo(philos, philo);
		return (NULL);
	}
	while (!philos->die_flag)
		philo_life(philos, philo);
	return (NULL);
}
