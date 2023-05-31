/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:27:59 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/31 15:22:14 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	get_time_start(t_philo *philo)
{
	struct timeval	ti;

	gettimeofday(&ti, NULL);
	philo->time_start = (ti.tv_sec * 1000 + ti.tv_usec / 1000);
}

long int	get_time_now(t_philo *philo)
{
	struct timeval	ti;
	long int		time_now;

	pthread_mutex_lock(&philo->time);
	gettimeofday(&ti, NULL);
	time_now = (ti.tv_sec * 1000 + ti.tv_usec / 1000);
	pthread_mutex_unlock(&philo->time);
	return (time_now - philo->time_start);
}

void	ft_usleep(t_philo *philo, long time)
{
	long	i;

	i = get_time_now(philo);
	while (philo->stop == 0)
	{
		if (get_time_now(philo) - i >= time)
			break ;
	}
}
