/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:46:02 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/11/02 21:46:09 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_FILO 200

typedef struct s_mutexes
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
}					t_mutexes;

typedef struct s_times
{
	size_t			die;
	size_t			eat;
	size_t			sleep;
	size_t			last_meal;
	size_t			born_time;
}					t_times;

typedef struct s_philo
{
	int				id;
	t_times			times;
	t_mutexes		mutexes;
	int				must_eat;
	pthread_t		thread_id;
	int				meals_eaten;
	int				philo_count;
}					t_philo;

typedef struct s_engine
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_engine;

void				init_philos(t_engine *en, t_philo *philos,
						pthread_mutex_t *forks, char **argv);
void				init_forks(t_engine *engine, pthread_mutex_t *forks,
						int count);
void				init_engine(t_engine *engine, t_philo *philos,
						pthread_mutex_t *forks);
int					is_all_eat(t_philo *philos);
void				*obsorver(void *ptr);
void				philo_routine(t_philo *philo);
void				*start_simulation(void *ptr);
void				launcher(t_engine *engine, int count);
void				error_message(char *text, int signal);
void				destroy_all(t_engine *engine, char *str, int count,
						int signal);
void				print_action(t_philo *philo, char *action);
size_t				get_current_time(void);
void				ft_usleep(size_t mls);
size_t				ft_strlen(const char *str);
long				ft_atoi(const char *str);

#endif
