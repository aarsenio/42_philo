/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:33:37 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/10 21:26:27 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_sleep(t_philo *philo, long int sleep_start)
{
	if (!check_dead() && philo->nbr_times_eat != data()->eat_nbr)
		print_msg(philo, "is sleeping");
	while (!check_dead() && ((get_time() - sleep_start) < data()->sleep_time))
	{
		is_dead(philo);
		usleep(1);
	}
	is_dead(philo);
	if (!check_dead() && philo->nbr_times_eat != data()->eat_nbr)
		print_msg(philo, "is thinking");
}

void	*routine(void *t)
{
	t_philo	*philo;

	philo = t;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (!check_dead() && philo->nbr_times_eat != data()->eat_nbr)
	{
		start_eat(philo);
		start_sleep(philo, get_time());
		is_dead(philo);
	}
	return (NULL);
}

void	philo_init(void)
{
	int		i;

	i = -1;
	data()->start = get_time();
	while (++i < data()->philo_nbr)
	{
		data()->philo[i].id = i + 1;
		data()->philo[i].nbr_times_eat = 0;
		data()->philo[i].fork = 0;
		data()->philo[i].last_meal = data()->start;
		pthread_create(&data()->philo[i].philo_thread, NULL, &routine, &data()->philo[i]);
	}
	i = -1;
	while (++i < data()->philo_nbr)
		pthread_join(data()->philo[i].philo_thread, NULL);
}
