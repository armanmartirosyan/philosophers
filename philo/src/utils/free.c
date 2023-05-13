/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:55:21 by armartir          #+#    #+#             */
/*   Updated: 2023/05/13 12:56:21 by armartir         ###   ########.fr       */
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
	int i;

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