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
	t_thread_list *me;

	me = import;
	while (me->philo->stop == 0)
	{
		printf("Thread start no : %d\n", me->number);
		sleep(2);
		printf("Thread finish\n");
		me->philo->stop = 1;
	}
	return (NULL);
}
