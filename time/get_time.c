/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:27:59 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/04 16:16:25 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void milliseconde_sleep(long int milliseconde)
{
    long int	start_time;
    long int    timer_ms;

	start_time = get_actual_time();
    timer_ms = get_time_pass(start_time, get_actual_time());
	while (timer_ms < milliseconde)
    {
        timer_ms = get_time_pass(start_time, get_actual_time());
        usleep(milliseconde / 1000);
    }
		
}

long int	get_time_pass(long int start, long int end)
{
	return (end - start);
}