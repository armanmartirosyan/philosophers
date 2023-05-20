/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:57:01 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 20:46:12 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/types.h>
# include <limits.h>

# include "defines.h"
# include "philo_struct.h"

// Initialization
void			chopstick_config(t_philos *philos);
int				philo_config(t_philos *philos, char **argv);
t_philos		*philo_init(t_philos *philos, char **argv);

// Utils
int				ft_isdigit(int c);
int				force_quit(char *msg);
void			*fail_init(void);
int				ft_atoi(const char *str);
void			*free_single(void **addr);
void			*free_double(void ***addr);
void			ft_putstr_fd(char *s, int fd);

// Messeges
void			dead_msg(t_philos *philos, t_philo *philo, unsigned int time);
int				print_msg(t_philos *philos, t_philo *philo, char *msg, int f);

// Time
unsigned int	ft_get_time(void);
void			ms_sleep(unsigned int time);

// Check args
int				check_args(char **argv, int argc);

// Free
void			free_all(t_philos *philos);
void			*free_double(void ***addr);
void			*free_single(void **addr);

// Life cycle
void			*start_matrix(t_philos *philos, t_philo *philo);
void			one_philo(t_philos *philos, t_philo *philo);
void			philo_life(t_philos *philos, t_philo *philo);
void			philo_sleep(t_philos *philos, t_philo *philo);
int				is_dead(t_philos *philos, t_philo *philo);
int				add_dead(t_philos *philos);
int				philo_start(t_philos *philos);
void			wait_philos(t_philos *philos);
void			*wait_eat(void *arg);

#endif