#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_arg	t_arg;

typedef struct s_philos
{
	int			philo_id;
	int			fork;
	int			count_philo;
	pthread_t	thread;

}	t_philos;

typedef struct s_arg
{
	int			num_philos;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			count_eat;
	t_philos	*philo;
}	t_arg;

/* src/parse_philo.c */
int		parse_args(int argc, char **argv, t_arg *args);
void	help_argv_validate(void);

/* src/parse_utils.c */
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *array);
int		cmp_atoi(char *atoi_nbr);

/* src/parse_utils2.c */
char	*ft_itoa(int n);

#endif
