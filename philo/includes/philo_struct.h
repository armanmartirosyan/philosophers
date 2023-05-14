/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:55:42 by armartir          #+#    #+#             */
/*   Updated: 2023/05/14 12:58:02 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct philos {
	pthread_t		*threads;
	pthread_mutex_t	death;
	pthread_mutex_t	death_flag;
	pthread_mutex_t	msg;
	int				hm_times;
	int				philo_num;
	int				die_flag;
	struct philo	*philo;
}	t_philos;

typedef struct philo {
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				id;
	int				times;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				last_meal;
	t_philos		*philos;
}	t_philo;

#endif