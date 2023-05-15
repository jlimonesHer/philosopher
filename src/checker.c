/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 07:44:56 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/13 07:57:45 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	checker_finish(t_arg *args)
{
	int	finish;

	finish = 0;
	pthread_mutex_lock(&args->mute_end_lock);
	if (args->end == 1)
		finish = 1;
	pthread_mutex_unlock(&args->mute_end_lock);
	return (finish);
}

int	check_dead(t_philos *philo)
{
	int	dead;

	dead = 0;
	pthread_mutex_lock(&philo->eat);
	if (ft_now() - philo->last_meal > philo->args->time_die)
		dead = 1;
	pthread_mutex_unlock(&philo->eat);
	if (dead == 1)
	{
		pthread_mutex_lock(&philo->args->mute_end_lock);
		philo->args->end = 1;
		pthread_mutex_unlock(&philo->args->mute_end_lock);
	}
	return (dead);
}