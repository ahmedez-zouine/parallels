#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PHILO 200

typedef	struct s_time
{
	size_t	t_eat;
	size_t	t_die;
	size_t	t_sleep;
	size_t	last_meal_take;
	size_t	date_init;
}		t_time;

typedef struct	s_sharing
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *meal_take;
	pthread_mutex_t	*console_take;
}	t_sharing;

typedef struct s_filo
{
	int id;
	int	nb_filo;
	size_t	meal_take;
	size_t	meal_must_take;
	pthread_t	thread_id;
	t_time	f_times;
	t_sharing d_share;
} t_filo;

typedef struct s_control
{
	t_filo	*filo;
	t_sharing *d_share;
	pthread_mutex_t	console_take;
	pthread_mutex_t meal_take;
} t_control;


// ---------------------- function ----------------- //

void ft_error_msg(int code, int codestatus);
void    ft_putstr_fd(char *str, int fd);
#endif //END P
