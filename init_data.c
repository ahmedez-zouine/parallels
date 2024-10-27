#include "philo.h"

void  ft_error_msg(int code, t_monitore *mn)
{
    if (code == 0)
        write(2, "Error in the ARGS\n", 18);
    else if (code == 1)
        write(2, "Plz check Value of the ARGS\n", 28);
    else if (code == 2)
        write(2, "Error\n", 6);
    if (mn != NULL)
        free(mn);
}

t_monitore *ft_init_monitore(int ac, char **av)
{
    t_monitore *mn;
    int is_error;
    int i;

    mn = (t_monitore *)malloc(sizeof(t_monitore));
    if (!mn)
        ft_error_msg(0, NULL);
    mn->nb_filo = atoi(av[1]);
    mn->t_die = atoi(av[2]);
    mn->t_sleep = atoi(av[4]);
    mn->t_eat = atoi(av[3]);
    mn->nb_must_eating = -1;
    if (av[5])
        mn->nb_must_eating = atoi(av[5]);
    if (is_error)
    {
        free(mn);
        return (NULL);
    }
    pthread_mutex_init(&mn->is_using, NULL);
    mn->forks = malloc(sizeof(pthread_mutex_t) * mn->nb_filo);
    if (!mn->forks)
    {
        ft_error_msg(0, mn);
        return (NULL);
    }
    i = 0;
    while (i < mn->nb_filo)
        pthread_mutex_init(&mn->forks[i++], NULL);
    // mn->s_time = get_current_time();
    mn->is_stop = 0;
    return (mn);
}

t_monitore  *ft_check_args(int ac, char **av)
{
    t_monitore *monitore;

    if(ac < 5 || ac > 6)
        ft_error_msg(1, NULL);
    monitore = ft_init_monitore(ac, av);
    if (!monitore)
        return (NULL);
    if (monitore->nb_filo < 1)
        ft_error_msg(2, monitore);
    if (monitore->t_die <= 0 || monitore->t_eat <= 0 || monitore->t_sleep <= 0)
        ft_error_msg(1, monitore);
    if (monitore->nb_must_eating != -1 && monitore->nb_must_eating <= 0)
        ft_error_msg(1, monitore);
    return (monitore);
}