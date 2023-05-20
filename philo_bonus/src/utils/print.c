/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:37:50 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 21:00:45 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_msg(t_philos *philos, t_philo *philo, char *msg, int f)
{
	unsigned int	time;

	time = ft_get_time();
	if (f && philos->hm_times != -1)
		philo->times++;
	sem_wait(philos->msg_sem);
	if (philos->die_flag == 0)
		printf ("Time: %u, %i - %s", time, philo->id, msg);
	sem_post(philos->msg_sem);
	return (time);
}

void	dead_msg(t_philos *philos, t_philo *philo, unsigned int time)
{
	sem_wait(philos->msg_sem);
	if (philos->die_flag == 1)
	{
		printf("Time: %u, %i - %s", time, philo->id, P_DEAD);
		sem_post(philos->dead_sem);
	}
}
