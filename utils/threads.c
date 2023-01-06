/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:33:37 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/06 17:56:17 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	is_dead(t_philo *philo)
{
	if ((get_time() - philo->last_meal) >= data()->die_time)
	{
		pthread_mutex_lock(&data()->mutex_dead);
		data()->dead++;
		if (data()->dead == 1)
			print_msg(philo, "died");
		pthread_mutex_unlock(&data()->mutex_dead);
	}
}

void	start_sleep(t_philo *philo, long int sleep_start)
{
	if (!data()->dead)
		print_msg(philo, "is sleeping");
	while ((get_time() - sleep_start) < data()->sleep_time)
	{
		is_dead(philo);
		usleep(1);
	}
	is_dead(philo);
	if (!data()->dead)
		print_msg(philo, "is thinking");
}

void	*routine(void *t)
{
	t_philo	*philo;

	philo = t;
	while (!data()->dead)
	{
		start_sleep(philo, get_time());
		is_dead(philo);
	}
	return (NULL);
}

void	philo_init(void)
{
	int		i;

	i = 0;
	data()->start = get_time();
	while (i < data()->philo_nbr)
	{
		data()->philo[i].id = i + 1;
		data()->philo[i].nbr_times_eat = 0;
		data()->philo[i].fork = 0;
		data()->philo[i].last_meal = data()->start;
		pthread_create(&data()->philo[i].philo_thread, NULL, &routine, &data()->philo[i]);
		i++;
	}
	i = 0;
	while (i < data()->philo_nbr)
		pthread_join(data()->philo[i++].philo_thread, NULL);
}
