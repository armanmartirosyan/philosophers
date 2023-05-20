/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:58:50 by armartir          #+#    #+#             */
/*   Updated: 2023/05/20 18:25:23 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// Philosopher behaviour
# define P_EAT "Philosopher is eating\n"
# define P_SLEEP "Philosopher is sleeping\n"
# define P_THINK "Philosopher is thinking\n"
# define P_DEAD "Philosopher is dead\n"
# define P_TFORK "Philosopher take fork\n"

// Custrom Errors
# define E_NOMEM "Memory allocation error!\n"
# define E_ARGNUM "Wrong number of arguments!\n"
# define E_CTHREAD "Failed to create new thread\n"
# define E_NEGNUM "Only positive numbers required\n"
# define E_PDETACH "Thread detach error\n"
# define E_FORK "Fork error\n"

// Semaphores
# define S_PHILO "/semaphore_philo"
# define S_MSG	"/semaphore_msg"
# define S_DEAD "/semaphore_dead"
#endif