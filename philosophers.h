/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/04 16:15:22 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_thread_list
{
	pthread_t				id;
	int						number;
	struct s_philo			*philo;
}					t_thread_list;

typedef struct s_philo
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_must_eat;
	int				stop;
	t_thread_list	*tab_thread;
	pthread_mutex_t	*tab_mutex_fork;
}					t_philo;

// init
void	init_struct(char **argv, t_philo *philo);
void	init_thread(t_philo *philo);
void	init_mutex_fork(t_philo *philo);

// check
void	check_arg(int argc, char **argv, t_philo *philo);
void	check_thread(t_philo *philo);

// util
int		str_to_int(const char *str);

// work
void *routine(void *philo);

// error
void	free_and_exit(t_philo *philo, char *msg, int force_exit);

#endif