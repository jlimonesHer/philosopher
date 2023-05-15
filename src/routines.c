/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:50:46 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/15 05:09:20 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *thread_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
		printf("id = %lu\n", (long)philos->philo_id);
		printf("count_eat = %lu\n", (long)philos->count_eat);
		printf("fork = %lu\n", (long)philos->fork);
		printf("last_meal = %lu\n", (long)philos->last_meal);
		printf("terminate = %lu\n", (long)philos->terminate);
		philos->count_eat++;
		printf("comidas que lleva despues del if %i\n", philos->count_eat);
	return (NULL);
}

void ft_eat()
{
	
}

void *routine(void *arg)
{
	(void)arg;
	printf("Te vigilo\n");
	return (0);
}