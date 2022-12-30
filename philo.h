/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:32:52 by aarsenio          #+#    #+#             */
/*   Updated: 2022/12/30 16:26:52 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data
{
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nbr;
	int				philo_nbr;
	unsigned long	start;
}t_data;

typedef struct s_philo
{
	int				id;
	int				nbr_times_eat;
	pthread_t		philo_thread;
}t_philo;

//STRUCTS FUNCTIONS
t_data	*data(void);
void	print_data(void);

//LIBRARY
int		ft_atoi(const char *str);
unsigned long	current_time(void);
unsigned long	time_diff(unsigned long last_action);

//PROGRAM
void	data_init(char **av);
void	philo_init(void);

#endif