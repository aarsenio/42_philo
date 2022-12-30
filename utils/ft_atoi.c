/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:35:17 by aarsenio          #+#    #+#             */
/*   Updated: 2022/12/30 13:35:53 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <limits.h>

int ft_atoi(const char *str)
{
    int i;
    long num;
    long signal;
    
    i = 0;
    num = 0;
    signal = 1;
    while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            signal = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + signal * (str[i++] - '0');
        if ((num < 0) || num > INT_MAX)
            return (-1);
    }
    return (num);
}
