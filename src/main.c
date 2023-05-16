/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:21 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 11:30:29 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	validate_args(int argc, char **argv, t_arg *args)
{
	(void) argv;
	(void) args;
	if ((argc != 5 && argc != 6))
	{
		help_argv_validate();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (!validate_args(argc, argv, &args))
		return (1);
	if (parse_args(argc, argv, &args))
		return (2);
	if (created_thread(&args))
		return (2);
	end_threads(&args);
	mutex_exit(&args);
	free_philo(&args);
	return (0);
}
