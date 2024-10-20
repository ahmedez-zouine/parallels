#ifndef PHILO
#define PHILO

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_data
{
    long number_of_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long number_of_times_each_philosopher_must_eat;
}    t_data;

typedef  struct s_philo
{
    t_data  *data;
    int      id;
    int      last_meal;
} t_philo;

// int ft_eating();
// int ft_thinking();
// int ft_sleeping();
// int ft_check_death();
// int ft_check_eat();
// int ft_init_philo(t_philo *philo, int i);
// int ft_init_data(t_data *data, int argc, char **argv);
// int ft_is_alive(t_philo *philo);
// int ft_is_dead(t_philo *philo);
// int ft_start_run();

#endif