/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/31 13:33:42 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
void	clear_thread(t_philo *philo)
{
	int i;
	
	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_destroy(philo->tab_thread[i].id, NULL);
		i++;
	}
}
*/

void	master_watch(t_philo *philo)
{
	long int	time;
	int			i;

	while (philo->stop == 0 && philo->actif_philo != 0)
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			time = get_time_now(philo);
			time = time - philo->tab_thread[i].last_meal;
			if (time >= philo->t_die && philo->tab_thread[i].nb_must_eat != 0)
				print_all(&philo->tab_thread[i], 5);
			i++;
		}
	}
}

int main (int argc, char **argv)
{
	t_philo	philo;

	philo = (t_philo){};
	check_arg(argc, argv, &philo);
	init_struct(argv, &philo);
	init_mutex_fork(&philo);
	get_time_start(&philo);
	init_thread(&philo);
	master_watch(&philo);
	return (0);
}
