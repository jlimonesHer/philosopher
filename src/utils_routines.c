/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:55:42 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 11:25:57 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	get_time(void)
{
	struct timeval	n_time;

	gettimeofday(&n_time, NULL);
	return (1000 * n_time.tv_sec + n_time.tv_usec / 1000);
}

void	is_sleep(time_t tm, t_arg *args)
{
	time_t	start;

	start = get_time();
	while (get_time() - start < tm && !checker_finish(args))
		usleep(1000);
}

void	print_action(t_philos *philo, char *action)
{
	int		dead_action;
	time_t	timestamp;

	dead_action = !ft_strncmp(action, DEAD, ft_strlen(action));
	pthread_mutex_lock(&philo->args->mute_lock);
	timestamp = get_time() - philo->args->start;
	if (!checker_finish(philo->args) || dead_action)
		printf("%ld %d %s", timestamp, philo->philo_id + 1, action);
	pthread_mutex_unlock(&philo->args->mute_lock);
}
