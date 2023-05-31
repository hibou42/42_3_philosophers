/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:43:59 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/31 13:31:08 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_all(t_thread_list *me, int nb)
{
	long int	time_now;
	pthread_mutex_lock(&me->philo->print);
	time_now = get_time_now(me->philo);
	if (me->philo->stop == 0)
	{
		printf("%ld %d ", time_now, me->number);
		if (nb == 1)
			printf("has taken a fork\n");
		if (nb == 2)
			printf("is eating\n");
		if (nb == 3)
			printf("is sleeping\n");
		if (nb == 4)
			printf("is thinking\n");
		if (nb == 5)
		{
			printf("died\n");
			me->philo->stop = 1;
		}
	}
	pthread_mutex_unlock(&me->philo->print);
}
