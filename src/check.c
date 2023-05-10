/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:29:44 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/10 16:07:31 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	check_arg(int argc, char **argv, t_philo *philo)
{
	int	i;
	int	j;

	if (argc > 6 || argc < 5)
		free_and_exit(philo, "Pas bon nombre d'arguments", 1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				free_and_exit(philo, "Arguments invalides", 1);
			j++;
		}
		i++;
	}
}

void	check_thread(t_philo *philo)
{
	int i;
	
	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_join(philo->tab_thread[i].id, NULL);
		i++;
	}
}