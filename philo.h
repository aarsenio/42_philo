/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:32:52 by aarsenio          #+#    #+#             */
/*   Updated: 2023/01/10 15:36:26 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_table
{
	int				have_fork;
	pthread_mutex_t	mutex_fork;
}t_table;

typedef struct s_philo
{
	
	int				id;
	int				nbr_times_eat;
	int				fork;
	long int		last_meal;
	pthread_t		philo_thread;
}t_philo;

typedef struct s_data
{
	int				dead;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nbr;
	int				philo_nbr;
	long int		start;
	pthread_mutex_t	mutex_dead;
	t_philo			*philo;
	t_table			*table;
}t_data;

//STRUCTS FUNCTIONS
t_data	*data(void);

//LIBRARY
int			ft_atoi(const char *str);
long int	get_time(void);
void		print_msg(t_philo *philo, char *msg);

//PROGRAM
void	data_init(char **av);
void	philo_init(void);
void	exit_program(void);

#endif