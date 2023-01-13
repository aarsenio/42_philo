/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:31:54 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/13 16:21:12 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		data_init(av);
		if (data()->die_time > 0 && data()->eat_time > 0 && \
			data()->sleep_time > 0 && data()->philo_nbr > 0)
			philo_init();
		exit_program();
	}
}
