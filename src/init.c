/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:27:59 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/10 14:50:40 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_struct(char **argv, t_philo *philo)
{
	philo->nb_philo = str_to_int(argv[1]);
	philo->actif_philo = philo->nb_philo;
	philo->t_die = str_to_int(argv[2]);
	philo->t_eat = str_to_int(argv[3]);
	philo->t_sleep = str_to_int(argv[4]);
	if (argv[5])
		philo->nb_must_eat = str_to_int(argv[5]);
	else
		philo->nb_must_eat = -1;
}

void	init_thread(t_philo *philo)
{
	int i;
	int	test;

	philo->tab_thread = malloc(sizeof(t_thread_list) * philo->nb_philo);
	if (!philo->tab_thread)
		free_and_exit(philo, "Impossible de créer les thread", 1);
	i = 0;
	while (i < philo->nb_philo)
	{	
		philo->tab_thread[i].number = i;
		philo->tab_thread[i].philo = philo;
		philo->tab_thread[i].nb_must_eat = philo->nb_must_eat;
		test = pthread_create(&philo->tab_thread[i].id, NULL, (void*)&routine, &philo->tab_thread[i]);
		if (test != 0)	
			free_and_exit(philo, "Thread init fail", 1);	
		i++;
	}
}

void	init_mutex_fork(t_philo *philo)
{
	int i;
	int	test;

	philo->tab_mutex_fork = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!philo->tab_mutex_fork)
		free_and_exit(philo, "Impossible de créer les mutex", 1);
	i = 0;
	while (i < philo->nb_philo)
	{
		test = pthread_mutex_init(&philo->tab_mutex_fork[i], NULL);
		if (test != 0)	
			free_and_exit(philo, "Tab fork mutex init fail", 1);
		i++;
	}
	test = pthread_mutex_init(&philo->print, NULL);
	if (test != 0)	
			free_and_exit(philo, "Print mutex init fail", 1);
}
