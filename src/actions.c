/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 05:23:14 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 11:01:43 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_sleep(t_philos *philo)
{
	if (philo->args->num_philos == 1)
		return ;
	print_action(philo, SLEEP);
	is_sleep(philo->args->time_sleep, philo->args);
}

void ft_think(t_philos *philo)
{
	print_action(philo, THINK);
}

void	ft_eat(t_philos *philo)
{
	if (philo->args->num_philos == 1)
		return ;
	pthread_mutex_lock(&philo->eat);
	print_action(philo, EAT);
	philo->count_eat++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eat);
	is_sleep(philo->args->time_eat, philo->args);
	pthread_mutex_unlock(&philo->fork_left);
	if (philo->args->num_philos != 1)
		pthread_mutex_unlock(philo->fork);
}

void	ft_take_forks(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	print_action(philo, FORK);
	if (philo->args->num_philos == 1)
	{
		pthread_mutex_lock(&philo->args->mute_end_lock);
		is_sleep(philo->args->time_die, philo->args);
		philo->args->end = 1;
		pthread_mutex_unlock(&philo->args->mute_end_lock);
		pthread_mutex_unlock(&philo->fork_left);
		print_action(philo, DEAD);
		return ;
	}
	pthread_mutex_lock(philo->fork);
	print_action(philo, FORK);
}