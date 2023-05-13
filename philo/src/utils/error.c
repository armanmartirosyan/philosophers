/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:51:06 by armartir          #+#    #+#             */
/*   Updated: 2023/05/13 14:52:48 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	force_quit(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (EXIT_FAILURE);
}

void	*fail_init(void)
{
	ft_putstr_fd("Failed to initialize - memory allocation problem", 2);
	return (NULL);
}
