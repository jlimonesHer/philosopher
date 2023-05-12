/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:50:46 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/12 18:13:16 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *thread_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
		printf("id = %i\n", philos->philo_id);
		philos->count_eat--;
		printf("comidas que lleva despues del if %i\n", philos->count_eat);
	
	// int i = 0;

	// philos = (t_philos *)arg;
	// while (++i < 2)
	// {
	// 	printf("id = %i\n", philos->philo_id);
	// 	usleep(100000);
	// 	printf("despues de usleep\n");
	// }
	// //pthread_detach(philos->thread);
	return (NULL);
}

void *routine(void *arg)
{
	(void)arg;
	while (1)
		;
	return (0);
}