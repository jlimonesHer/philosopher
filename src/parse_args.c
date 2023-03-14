/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:16 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/14 17:32:06 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	parse_args(int argc, char **argv, t_arg *args)
{
	args->num_philos = cmp_atoi(argv[1]);
	args->time_die = cmp_atoi(argv[2]);
	args->time_eat = cmp_atoi(argv[3]);
	args->time_sleep = cmp_atoi(argv[4]);
	args->count_eat = -1;
	if (args->num_philos < 1 || args->time_die < 1 || args->time_eat < 1
		|| args->time_sleep < 1)
		return (1);
	if (argc == 6)
	{
		args->count_eat = cmp_atoi(argv[5]);
		if (args->count_eat < 1)
			return (1);
	}
	return (0);
}

/**
 * Escribe en el fd pasado por parametro.
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i++], 1);
	}
}

/**
 * @brief muestra el error y mensaje de ayuda para argumentos no validos.
 * 
 * @param error 
 */
void	help_argv_validate(void)
{
	ft_putstr_fd("error", 2);
	printf("\n");
	printf("Help:\n");
	printf("	[./philo n n n n n n]\n");
	exit(-1);
}
