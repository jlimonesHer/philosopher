/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:16 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/12 18:08:46 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	fill_philos(t_arg *args_philo)
{
	int			i;
	t_philos	*philos;

	i = -1;
	philos = malloc(sizeof(t_philos) * args_philo->num_philos);
	while (args_philo->num_philos > ++i)
	{
		philos->args = args_philo;
		philos[i].philo_id = i + 1;
		philos[i].fork = 1;
		philos[i].count_philo = 1;
		philos[i].count_eat = args_philo->count_eat;
	}
	args_philo->philo = philos;
}

int	parse_args(int argc, char **argv, t_arg *args_philo)
{
	args_philo->num_philos = cmp_atoi(argv[1]);
	args_philo->time_die = cmp_atoi(argv[2]);
	args_philo->time_eat = cmp_atoi(argv[3]);
	args_philo->time_sleep = cmp_atoi(argv[4]);
	args_philo->count_eat = -1;
	pthread_mutex_init(&(args_philo->mute_eat), NULL);
	if (args_philo->num_philos < 1 || args_philo->time_die < 1
		|| args_philo->time_eat < 1
		|| args_philo->time_sleep < 1)
		return (1);
	if (argc == 6)
		args_philo->count_eat = cmp_atoi(argv[5]);
	if (args_philo->count_eat < 1)
		return (1);
	fill_philos(args_philo);
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
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Help:\n", 2);
	ft_putstr_fd("	[./philo n n n n n n]\n", 2);
	exit(-1);
}
