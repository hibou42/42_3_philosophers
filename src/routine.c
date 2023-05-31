/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:22 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/31 15:34:51 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_sleep(t_thread_list *me)
{
	print_all(me, 3);
	ft_usleep(me->philo, me->philo->t_sleep);
	print_all(me, 4);
}

void	ft_eat(t_thread_list *me, int next)
{
	pthread_mutex_lock(&me->philo->tab_mutex_fork[me->number]);
	print_all(me, 1);
	pthread_mutex_lock(&me->philo->tab_mutex_fork[next]);
	print_all(me, 1);
	me->last_meal = get_time_now(me->philo);
	print_all(me, 2);
	ft_usleep(me->philo, me->philo->t_eat);
	pthread_mutex_unlock(&me->philo->tab_mutex_fork[me->number]);
	pthread_mutex_unlock(&me->philo->tab_mutex_fork[next]);
	if (me->nb_must_eat != -1)
		me->nb_must_eat--;
}

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
		ft_usleep(me->philo, me->philo->t_eat / 2);
	while (me->philo->stop == 0 && me->nb_must_eat != 0)
	{
		ft_eat(me, next);
		ft_sleep(me);
	}
	me->philo->actif_philo--;
	return (NULL);
}
