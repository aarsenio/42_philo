/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:33:37 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/10 16:26:02 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_dead(void)
{
	int	death;

	pthread_mutex_lock(&data()->mutex_dead);
	death = data()->dead;
	pthread_mutex_unlock(&data()->mutex_dead);
	return (death);
}

void	is_dead(t_philo *philo)
{
	if ((get_time() - philo->last_meal) >= data()->die_time)
	{
		pthread_mutex_lock(&data()->mutex_dead);
		if (data()->dead < 3)
			data()->dead++;
		if (data()->dead == 1)
			print_msg(philo, "died");
		pthread_mutex_unlock(&data()->mutex_dead);
	}
}

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
	while (!check_dead() && philo->nbr_times_eat != data()->eat_nbr)
	{
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
