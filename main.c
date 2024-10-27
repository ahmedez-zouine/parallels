#include "philo.h"


void ft_printData(t_monitore *mn)
{
    printf("%lu\n",mn->t_die);
    printf("%lu\n",mn->t_eat);
    printf("%lu\n",mn->t_sleep);
    printf("%d\n",mn->is_stop);
    printf("%lu\n",mn->nb_must_eating);
    printf("%lu\n",mn->nb_filo);
}

int main(int argc, char **argv)
{
    t_monitore *monitore;
    t_filo      *filo;

    monitore = ft_check_args(argc, argv);
    ft_printData(monitore);
}