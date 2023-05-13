/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:56:43 by armartir          #+#    #+#             */
/*   Updated: 2023/05/13 17:39:16 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_matrix(void *arg)
{
	t_philo		*philo;
	t_philos	*philos;
	
	philo = (t_philo *)arg;
	philos = philo->philos;
	if (philos->philo_num == 1)
	{
		print_msg(philos, philo, P_TFORK);
		ms_sleep(philo->time_to_die);
		philos->die_flag++;
		dead_msg(philos, philo, ft_get_time());
		return (NULL);
	}
	if (philo->id % 2)
		ms_sleep(philos->time_to_eat);
	// while (!philos->die_flag)
	// TODO: write philo_life
		// philo_life(philos, philo);
	return (NULL);
}

int	philo_start(t_philos *philos)
{
	int		i;

	i = -1;
	while (++i < philos->philo_num)
		if (pthread_create(&philos->threads[i], NULL, &start_matrix, &philos->philo[i]))
			return (force_quit(E_CTHREAD));
	i = -1;
	while (++i < philos->philo_num)
		if (pthread_join(philos->threads[i], NULL))
			return (force_quit(E_CTHREAD));
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_philos    		 *philos;

	if (argc < 5 || argc > 6)
		return (force_quit(E_ARGNUM));
	// TODO: check args
	philos = philo_init(philos, argv);
	if (!philos)
		return (EXIT_FAILURE);
	if (philo_start(philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);




	// int i = 0;
	// while (i < philos->philo_num)
	// {
	// 	printf("Left:%d  %p    Right:%d %p\n", i, philos->philo[i].left, i, philos->philo[i].right);
	// 	i++;
	// }
}