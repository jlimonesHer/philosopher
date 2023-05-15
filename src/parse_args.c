/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:16 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/15 05:03:14 by jlimones         ###   ########.fr       */
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
		philos[i].philo_id = i;
		philos[i].terminate = 0;
		philos[i].count_eat = 0;
		philos[i].fork = &philos[(i + 1) % args_philo->num_philos].fork_left;
		pthread_mutex_init(&philos[i].fork_left, 0);
		pthread_mutex_init(&philos[i].eat, 0);
		philos->last_meal = get_time();
		philos[i].args = args_philo;
	}
	args_philo->philo = philos;
	args_philo->start = get_time();
	args_philo->end = 0;
	args_philo->philo = philos;
}

/**
 * @brief 
 * 
 * @param argc numero de argumentos
 * @param argv argumentos
 * @param args_philo estructura de argumentos
 * @return int 0 si el parse es correcto,1 si no lo es
 */
int	parse_args(int argc, char **argv, t_arg *args_philo)
{
	args_philo->num_philos = cmp_atoi(argv[1]);
	args_philo->time_die = cmp_atoi(argv[2]);
	args_philo->time_eat = cmp_atoi(argv[3]);
	args_philo->time_sleep = cmp_atoi(argv[4]);
	args_philo->count_eat = -1;
	if (args_philo->num_philos < 1 || args_philo->time_die < 1
		|| args_philo->time_eat < 1
		|| args_philo->time_sleep < 1)
		return (1);
	if (argc == 6)
	{
		args_philo->count_eat = cmp_atoi(argv[5]);
		if (args_philo->count_eat < 1)
			return (1);
	}
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
 */
void	help_argv_validate(void)
{
	ft_putstr_fd("error", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Help:\n", 2);
	ft_putstr_fd("	[./philo n n n n n]\n", 2);
	ft_putstr_fd("	[./philo n n n n]\n", 2);
	exit(-1);
}
