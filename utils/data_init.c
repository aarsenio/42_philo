/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:45:11 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/10 16:22:03 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	data_init(char **av)
{
	int	i;

	i = -1;
	data()->dead = 0;
	data()->philo_nbr = ft_atoi(av[1]);
	data()->die_time = ft_atoi(av[2]);
	data()->eat_time = ft_atoi(av[3]);
	data()->sleep_time = ft_atoi(av[4]);
	if (av[5])
		data()->eat_nbr = ft_atoi(av[5]);
	else
		data()->eat_nbr = -1;
	data()->philo = malloc(sizeof(t_philo) * data()->philo_nbr);
	if (!data()->philo)
		return ;
	data()->table = malloc(sizeof(t_table) * data()->philo_nbr);
	if (!data()->table)
		return ;
	pthread_mutex_init(&data()->mutex_dead, NULL);
	i = -1;
	while (++i < data()->philo_nbr)
	{
		pthread_mutex_init(&data()->table[i].mutex_fork, NULL);
		data()->table[i].have_fork = 1;
	}
}
