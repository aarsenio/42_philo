/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_call.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:45:33 by aarsenio          #+#    #+#             */
/*   Updated: 2022/12/30 16:22:03 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	print_data(void)
{
	printf("%i philo\n", data()->philo_nbr);
    printf("%i die time\n", data()->die_time);
    printf("%i eat time\n", data()->eat_time);
    printf("%i sleep time\n",data()->sleep_time);
    printf("%i eat nbr\n",data()->eat_nbr);
	printf("%li start\n",data()->start);
}
