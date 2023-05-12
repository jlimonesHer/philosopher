/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:21 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/12 12:51:40 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	validate_args(int argc, char **argv, t_arg *args)
{
	if ((argc != 5 && argc != 6) || parse_args(argc, argv, args))
	{
		help_argv_validate();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	validate_args(argc, argv, &args);
	created_thread(&args);
	return (0);
}
