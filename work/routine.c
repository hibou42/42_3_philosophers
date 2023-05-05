/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:22 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/04 16:24:58 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void *routine(void *import)
{
	t_thread_list	*me;
	int				next;

	me = import;
	if (me->number == (me->philo->nb_philo - 1))
		next = 0;
	else
		next = me->number + 1;
	if ((me->number % 2) != 0)
		sleep(1);
	while (me->philo->stop == 0)
	{
		printf("Thread start no : %d next is : %d\n", me->number, next);
		pthread_mutex_lock(&me->philo->tab_mutex_fork[me->number]);
		pthread_mutex_lock(&me->philo->tab_mutex_fork[next]);
		printf("Miam miam thread nb %d\n", me->number);
		sleep(1);
		pthread_mutex_unlock(&me->philo->tab_mutex_fork[me->number]);
		pthread_mutex_unlock(&me->philo->tab_mutex_fork[next]);
		me->philo->stop = 1;
	}
	printf("Thread stop no : %d\n", me->number);
	return (NULL);
}
