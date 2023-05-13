/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:11:55 by armartir          #+#    #+#             */
/*   Updated: 2023/05/13 16:33:19 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	ft_get_time(void)
{
	struct timeval		time;
	static int			flag;
	static unsigned int	start;

	if (flag == 0)
	{
		gettimeofday(&time, NULL);
		start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		flag++;
	}
	else
		gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

void	ms_sleep(unsigned int time)
{
	usleep(time * 1000);
}
