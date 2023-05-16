/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:50:46 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 11:59:13 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*thread_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	if (philos->philo_id % 2)
	{
		while (!checker_finish(philos->args))
		{
			ft_sleep(philos);
			ft_think(philos);
			ft_take_forks(philos);
			ft_eat(philos);
		}
	}
	else
	{
		while (!checker_finish(philos->args))
		{
			ft_take_forks(philos);
			ft_eat(philos);
			ft_sleep(philos);
			ft_think(philos);
		}
	}
	return (NULL);
}
