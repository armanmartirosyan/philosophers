/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:56:43 by armartir          #+#    #+#             */
/*   Updated: 2023/05/14 13:09:24 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_start(t_philos *philos)
{
	int		i;

	i = -1;
	while (++i < philos->philo_num)
		if (pthread_create(&philos->threads[i], NULL,
				&start_matrix, &philos->philo[i]))
			return (force_quit(E_CTHREAD));
	i = -1;
	while (++i < philos->philo_num)
		if (pthread_join(philos->threads[i], NULL))
			return (force_quit(E_CTHREAD));
	free_all(philos);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philos	*philos;

	if (argc < 5 || argc > 6)
		return (force_quit(E_ARGNUM));
	if (check_args(argv, argc))
		return (force_quit(E_NEGNUM));
	philos = NULL;
	philos = philo_init(philos, argv);
	if (!philos)
		return (EXIT_FAILURE);
	if (philo_start(philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
