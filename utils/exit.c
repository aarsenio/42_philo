/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:48:08 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/11 11:04:08 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	exit_program(void)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data()->mutex_dead);
	while (++i < data()->philo_nbr)
		pthread_mutex_destroy(&data()->table[i].mutex_fork);
	if (data()->table)
		free(data()->table);
	if (data()->philo)
		free(data()->philo);
	exit(0);
}
