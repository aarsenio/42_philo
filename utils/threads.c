/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:33:37 by aarsenio          #+#    #+#             */
/*   Updated: 2022/12/30 16:16:51 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*test(void *philo)
{
	t_philo	*t;

	t = philo;
	printf("philo id: %i\n", t->id);
	sleep(2);
	printf("philo nbr eat: %i\n", t->nbr_times_eat);
	return (NULL);
}

void	philo_init(void)
{
	t_philo	philo[data()->philo_nbr];
	int		i;

	i = 0;
	while (i < data()->philo_nbr)
	{
		philo[i].id = i + 1;
		philo[i].nbr_times_eat = 0;
		pthread_create(&philo[i].philo_thread, NULL, &test, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data()->philo_nbr)
		pthread_join(philo[i++].philo_thread, NULL);
}
