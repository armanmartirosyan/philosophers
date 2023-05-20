/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:55:42 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 16:22:18 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct philos {
	sem_t			*msg_sem;
	sem_t			*dead_sem;
	sem_t			*philos_sem;
	int				hm_times;
	int				philo_num;
	int				die_flag;
	struct philo	*philo;
}	t_philos;

typedef struct philo {
	int				id;
	int				times;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				last_meal;
	t_philos		*philos;
	pid_t			pid;
}	t_philo;

#endif