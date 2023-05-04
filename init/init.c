/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:27:59 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/04 16:16:25 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_struct(char **argv, t_philo *philo)
{
	philo->nb_philo = str_to_int(argv[1]);
	philo->t_die = str_to_int(argv[2]);
	philo->t_eat = str_to_int(argv[3]);
	philo->t_sleep = str_to_int(argv[4]);
	if (argv[5])
		philo->nb_must_eat = str_to_int(argv[5]);
}

void	init_thread(t_philo *philo)
{
	int i;

	philo->tab_thread = malloc(sizeof(t_thread_list) * philo->nb_philo);
	i =0;
	while (i < philo->nb_philo)
	{
		//				ou il est enregistre, osef, address code a exec, param entree code a exec
		pthread_create(&philo->tab_thread[i].id, NULL, (void*)&routine, &philo->tab_thread[i]);
		philo->tab_thread[i].number = i;
		philo->tab_thread[i].philo = philo;
		i++;
	}
}

void	init_mutex_fork(t_philo *philo)
{
	int i;

	philo->tab_mutex_fork = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	i =0;
	while (i < philo->nb_philo)
	{
		pthread_mutex_init(&philo->tab_mutex_fork[i], NULL);
		i++;
	}
}