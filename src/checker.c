/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 07:44:56 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 11:57:31 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_eat(t_arg *args)
{
	int	i;
	int	status;

	i = -1;
	status = 1;
	if (args->count_eat == -1)
		return (0);
	while (++i < args->num_philos)
	{
		pthread_mutex_lock(&args->philo[i].eat);
		if (args->philo[i].count_eat < args->count_eat)
			status = 0;
		pthread_mutex_unlock(&args->philo[i].eat);
	}
	if (status)
	{
		pthread_mutex_lock(&args->mute_end_lock);
		args->end = 1;
		pthread_mutex_unlock(&args->mute_end_lock);
	}
	return (status);
}

void	*routine_check(void *arg)
{
	t_arg	*args;
	int		i;

	args = (t_arg *)arg;
	while (!checker_finish(args))
	{
		i = -1;
		while (++i < args->num_philos)
		{
			if (check_dead(&args->philo[i]))
			{
				print_action(&args->philo[i], DEAD);
				return (NULL);
			}
			else if (check_eat(args))
				return (NULL);
		}
	}
	return (NULL);
}

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
	if (get_time() - philo->last_meal > philo->args->time_die)
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
