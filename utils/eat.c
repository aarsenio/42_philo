/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:41:21 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/11 11:05:07 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	take_fork(t_philo *philo, int slot)
{
	pthread_mutex_lock(&data()->table[slot].mutex_fork);
	if (data()->table[slot].have_fork)
	{
		data()->table[slot].have_fork = 0;
		philo->fork++;
		if (!check_dead() && philo->nbr_times_eat != data()->eat_nbr)
			print_msg(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&data()->table[slot].mutex_fork);
}

static void	return_fork(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&data()->table[left].mutex_fork);
	data()->table[left].have_fork = 1;
	pthread_mutex_unlock(&data()->table[left].mutex_fork);
	pthread_mutex_lock(&data()->table[right].mutex_fork);
	data()->table[right].have_fork = 1;
	pthread_mutex_unlock(&data()->table[right].mutex_fork);
	philo->fork = 0;
}

void	start_eat(t_philo *philo)
{
	long int	eat_start;
	int			left;
	int			right;

	left = philo->id - 1;
	right = (philo->id != data()->philo_nbr) * philo->id;
	while (!check_dead() && philo->fork != 2)
	{
		take_fork(philo, left);
		take_fork(philo, right);
		is_dead(philo);
	}
	eat_start = get_time();
	if (!check_dead() && (philo->nbr_times_eat <= data()->eat_nbr || \
		data()->eat_nbr == -1))
		print_msg(philo, "is eating");
	while (!check_dead() && ((get_time() - eat_start) < data()->eat_time))
		usleep(1);
	philo->last_meal = get_time();
	if (data()->eat_nbr != -1)
		philo->nbr_times_eat++;
	return_fork(philo, left, right);
}
