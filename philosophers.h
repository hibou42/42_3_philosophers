/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/04/26 14:57:53 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "./libft/libft.h"
#include <pthread.h>

typedef struct s_c_list
{
	int				content;
	struct s_c_list	*next;
}					t_c_list;

typedef struct s_philo
{
	int			solo;
	int			multi;
	int			nb_nbr;
	t_c_list	*p_a;
	t_c_list	*p_b;
}					t_philo;

void	test(void);

#endif