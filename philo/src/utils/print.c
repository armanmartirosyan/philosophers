/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:37:50 by armartir          #+#    #+#             */
/*   Updated: 2023/05/14 13:30:31 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_msg(t_philos *philos, t_philo *philo, char *msg, int f)
{
	unsigned int	time;

	pthread_mutex_lock(&philos->msg);
	time = ft_get_time();
	if (f && philos->hm_times != -1)
		philo->times++;
	if (philos->die_flag == 0)
		printf ("Time: %u, %i - %s", time, philo->id, msg);
	pthread_mutex_unlock(&philos->msg);
	return (time);
}

void	dead_msg(t_philos *philos, t_philo *philo, unsigned int time)
{
	pthread_mutex_lock(&philos->msg);
	if (philos->die_flag == 1)
		printf("Time: %u, %i - %s", time, philo->id, P_DEAD);
	pthread_mutex_unlock(&philos->msg);
}
