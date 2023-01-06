/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:45:11 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/06 16:11:28 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	data_init(char **av)
{
	data()->dead = 0;
	data()->philo_nbr = ft_atoi(av[1]);
	data()->die_time = ft_atoi(av[2]);
	data()->eat_time = ft_atoi(av[3]);
	data()->sleep_time = ft_atoi(av[4]);
	if (av[5])
		data()->eat_nbr = ft_atoi(av[5]);
	else
		data()->eat_nbr = -1;
	pthread_mutex_init(&data()->mutex_dead, NULL);
	data()->philo = malloc(sizeof(t_philo) * data()->philo_nbr);
	if (!data()->philo)
		return ;
}
