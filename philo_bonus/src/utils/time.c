/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:11:55 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 20:48:01 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	ft_get_time(void)
{
	struct timeval		tv;
	static int			count;
	static unsigned int	start;

	if (count == 0)
	{
		gettimeofday(&tv, NULL);
		start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		count++;
	}
	else
		gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start);
}

void	ms_sleep(unsigned int time)
{
	struct timeval	now;
	struct timeval	start;

	gettimeofday(&now, NULL);
	gettimeofday(&start, NULL);
	while ((now.tv_sec - start.tv_sec) * 1000 + \
		(now.tv_usec - start.tv_usec) / 1000 <= time)
	{
		usleep(10);
		gettimeofday(&now, NULL);
	}
}
