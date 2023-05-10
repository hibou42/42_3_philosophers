/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:30:48 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/04 15:34:57 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_and_exit(t_philo *philo, char *msg, int force_exit)
{
	(void)philo;
	//clean struct
	printf("Error : %s\n", msg);
	if (force_exit != 0)
		exit(1);
}