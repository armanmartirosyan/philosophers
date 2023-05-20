/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:55:21 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 16:13:43 by armartir         ###   ########.fr       */
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
	free_single((void *)&philos->philo);
	unlink(S_DEAD);
	unlink(S_MSG);
	unlink(S_PHILO);
	free_single((void *)&philos);
}
