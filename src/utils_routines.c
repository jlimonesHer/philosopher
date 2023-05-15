/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:55:42 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/13 07:43:10 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	get_time(void)
{
	struct timeval	n_time;

	gettimeofday(&n_time, NULL);
	return (1000 * n_time.tv_sec + n_time.tv_usec / 1000);
}