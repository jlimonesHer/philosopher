/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:55:42 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/12 14:55:58 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	ft_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (1000 * now.tv_sec + now.tv_usec / 1000);
}