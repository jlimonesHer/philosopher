/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:56:26 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 11:57:54 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define EAT "is eating\n"
# define FORK "has taken a fork\n"
# define DEAD "died\n"

typedef struct s_arg	t_arg;

typedef struct s_philos
{
	int					philo_id;
	pthread_mutex_t		eat;
	pthread_mutex_t		*fork;
	pthread_mutex_t		fork_left;
	int					terminate;
	int					count_eat;
	time_t				last_meal;
	t_arg				*args;
}	t_philos;

typedef struct s_arg
{
	int					num_philos;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					count_eat;
	int					end;
	time_t				start;
	t_philos			*philo;
	pthread_t			*thread;
	pthread_mutex_t		mute_lock;
	pthread_mutex_t		mute_end_lock;
}	t_arg;

/* src/parse_args.c */
int			parse_args(int argc, char **argv, t_arg *args);
void		help_argv_validate(void);

/* src/parse_utils.c */
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(char *array);
int			cmp_atoi(char *atoi_nbr);

/* src/parse_utils2.c */
char		*ft_itoa(int n);

/*created_th.c*/
int			created_thread(t_arg *args);

/*routines.c*/
void		*thread_routine(void *arg);

/*checker.c*/
int			checker_finish(t_arg *args);
int			check_eat(t_arg *args);
void		*routine_check(void *arg);
int			check_dead(t_philos *philo);

/*actions.c*/
void		ft_sleep(t_philos *philo);
void		ft_think(t_philos *philo);
void		ft_eat(t_philos *philo);
void		ft_take_forks(t_philos *philo);

/*utils_routines.c*/
time_t		get_time(void);
void		is_sleep(time_t tm, t_arg *args);
void		print_action(t_philos *philo, char *action);

/*exit.c*/
void		mutex_exit(t_arg *args);
void		end_threads(t_arg *args);
void		free_philo(t_arg *args);
#endif
