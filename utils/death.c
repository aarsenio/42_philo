/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:28:58 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/10 16:29:31 by aarsenio         ###   ########.fr       */
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
