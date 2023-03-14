#include "../include/philo.h"

void *thread_routine(void *arg)
{
	char *texto = (char*) arg;
	while (1)
	{
		printf("%s\n", texto);
		usleep(1000000);
	}
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (argc != 5 && argc != 6)
		help_argv_validate();
	if (parse_args(argc, argv, &args))
		help_argv_validate();
	return (0);
}