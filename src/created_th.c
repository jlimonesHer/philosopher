/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_th.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:48:53 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/15 06:27:23 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	created_thread(t_arg *args)
{
	int			i;
	pthread_t	watch;

	i = -1;
	args->thread = malloc(sizeof(pthread_t) * args->num_philos);
	if (args->thread == NULL)
		return (1);
	while (++i < args->num_philos)
	{
		if (pthread_create(&args->thread[i], NULL,
				thread_routine, &args->philo[i]))
			return (1);
       // pthread_join(args->thread[i], NULL);
	}
	if (pthread_create(&watch, NULL, routine_check, (void *)args))
		return (1);
	pthread_join(watch, NULL);
	return (0);
}