/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/04/26 14:57:53 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *text)
{
	printf("Thread [%s]\n", (char *)text);
	sleep(2);
	printf("Thread finish\n");
	return (NULL);
}

int main (int argc, char **argv)
{
    t_philo philo;

    philo = (t_philo){};
    (void)philo;
    (void)argc;
    (void)argv;

    pthread_t t1;
	pthread_t t2;
	char *test = "hello world";
	char *test2 = "goodbye world";
	
	pthread_create(&t1, NULL, &routine, test);
	pthread_create(&t2, NULL, &routine, test2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
