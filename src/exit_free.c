/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:11:12 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 10:13:53 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	mutex_exit(t_arg *args)
{
	int	i;

	i = -1;
	while (++i < args->num_philos)
	{
		pthread_mutex_destroy(&args->philo[i].fork_left);
		pthread_mutex_destroy(&args->philo[i].eat);
	}
	pthread_mutex_destroy(&args->mute_end_lock);
	pthread_mutex_destroy(&args->mute_lock);
}

void	end_threads(t_arg *args)
{
	int	i;

	i = -1;
	while (++i < args->num_philos)
		pthread_join(args->thread[i], NULL);
}

void	free_philo(t_arg *args)
{
	free(args->philo);
	free(args->thread);
}
