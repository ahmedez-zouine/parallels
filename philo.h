#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>


typedef struct t_monitore
{
    size_t  nb_filo;
    size_t  t_die;
    size_t  t_eat;
    size_t  t_sleep;
    size_t  nb_must_eating;
    size_t  s_time;
    pthread_mutex_t *forks;
    pthread_mutex_t is_using;
    int     is_stop;
}   t_monitore;

typedef struct s_filo
{
    int     id_philo;
    pthread_t   p_thread;
    size_t  last_eating;
    pthread_mutex_t *f_fork;
    pthread_mutex_t *s_fork;
    t_monitore  *monitore;
    struct s_filo *next;
}   t_filo;

// -------------> Function <---------------------

// void  error_msg(int code, t_monitore *mn);
t_monitore  *ft_check_args(int ac, char **av);
t_monitore *ft_init_monitore(int ac, char **av);
// void  error_msg(int code, t_monitore *mn);
// size_t  get_current_time();
#endif