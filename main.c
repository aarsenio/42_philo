/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:31:54 by aarsenio          #+#    #+#             */
/*   Updated: 2022/12/30 16:21:29 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    if (ac == 5 || ac == 6)
	    data_init(av);
    data()->start = current_time();
    print_data();
	philo_init();
}
