#include "../include/philo.h"

void *thread_routine(void *arg)
{
	t_philos	*philos;
	//int			i = 1;

	philos = (t_philos *)arg;
	while (1)
	{
		printf("id = %i\n", philos->philo_id);
		usleep(10000);
		printf("despues de usleep\n");
		//i--;
	}
	return (NULL);
}

void *routine(void *arg)
{
	(void) arg;
	while (1)
		;
}

void	created_thread(t_arg *args)
{
	int	i;
	pthread_t waiter;

	i = -1;
	while (++i < args->num_philos)
	{
		pthread_create(&args->philo[i].thread, NULL,
			thread_routine, &args->philo[i]);
	}
	pthread_create(&waiter, NULL, routine, NULL);
	pthread_join(waiter, NULL);
}

void	print_struct(t_arg *args)
{
	int		i;

	i = 0;
	printf("argc[%i] = %i\n", i, args->num_philos);
	printf("argc[%i] = %i\n", i, args->time_die);
	printf("argc[%i] = %i\n", i, args->time_eat);
	printf("argc[%i] = %i\n", i, args->time_sleep);
	printf("argc[%i] = %i\n", i, args->count_eat);
	// i = -1;
	// while (args->num_philos > i++)
	// {
	// 	printf("id = %i\n", args->philo[i].philo_id);
	// }
}

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
	int		i;

	i = -1;
	validate_args(argc, argv, &args);
	//print_struct(&args);
	created_thread(&args);
	return (0);
}
