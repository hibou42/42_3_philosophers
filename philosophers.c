/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/04 16:35:03 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void test(t_philo *philo)
{
	printf("%d\n", philo->nb_philo);
	printf("%d\n", philo->t_die);
	printf("%d\n", philo->t_eat);
	printf("%d\n", philo->t_sleep);
	printf("%d\n", philo->nb_must_eat);
}

int main (int argc, char **argv)
{
	t_philo philo;

	philo = (t_philo){};
	check_arg(argc, argv, &philo);
	init_struct(argv, &philo);
	init_mutex_fork(&philo);
	test(&philo);
	init_thread(&philo);
	check_thread(&philo);
	return (0);
}

/*
number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/