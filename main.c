/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:31:54 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/11 11:03:26 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		data_init(av);
		if (data()->die_time && data()->eat_time && \
			data()->sleep_time && data()->philo_nbr)
			philo_init();
		exit_program();
	}
}
