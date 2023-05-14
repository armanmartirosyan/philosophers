/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:55:21 by armartir          #+#    #+#             */
/*   Updated: 2023/05/14 12:02:05 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*free_single(void **addr)
{
	if (*addr)
	{
		free (*addr);
		*addr = 0;
	}
	return (0);
}

void	*free_double(void ***addr)
{
	int	i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free_single((void *)&(*addr)[i]);
			i++;
		}
		free_single((void *)&(*addr));
	}
	return (0);
}

void	free_all(t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < philos->philo_num)
		pthread_mutex_destroy(&philos->philo[i].mutex);
	free_single((void *)&philos->philo);
	free_single((void *)&philos->threads);
	free_single((void *)&philos);
}
