#include "philo.h"

void ft_error_msg(int code, int codestatus)
{
	if (code == 0)
		ft_putstr_fd("Malloc  failed\n", 2);
	if  (code == 1)
		ft_putstr_fd("Error: Invalid argument\n", 2);
	if  (code == 2)
		ft_putstr_fd("Error: Invalid Value of arguments\n", 2);
	if (codestatus != -1)
		exit(codestatus);
}

void ft_check_args(int argc, char **av)
{
	int nb;
	int i;

	if (argc < 5 || argc > 6)
		ft_error_msg(1, 2);
	i = 1;
	while (i < argc)
	{
		nb = atoi(av[i]);
		printf("args[%d]--> %d\n", i, nb);
		if (i == 1 && (nb <= 0 || nb >= MAX_PHILO))
			ft_error_msg(2, 2);
		else if (nb == 5 && (nb < 0 || nb > INT_MAX))
			ft_error_msg(1, 2);
		else if (i != 1 && i != 5 && (nb < 1 || nb > INT_MAX))
			ft_error_msg(2, 2);
		i++;
	}
}

void	ft_init_forks(t_control *cnl, t_sharing *forks, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
	{
		if (pthread_mutex_init(&froks[i], NULL) != 0)
			ft_destroy_all(cnl, "Mutex init Error\n", i, 1);
	}
}

void	ft_init_control(t_control *cnl, t_filo *file, t_sharing *froks)
{
	cnl->filo = filo;
	cnl->forks = forks;
	if (pthread_mutex_init(&cnl->console_take, NULL) != 0 || 
			pthread_mutex_init(&cnl->meal_take) != 0 )
		{
			ft_destroy_all(cnl, "ERROR IN THE INIT MUTEXT Cnl\n", -1, 1);
		}
}

void	ft_init_filo(t_control *cnl, t_filos *filo, t_sharing *froks, char **av)
{
	int i;

	i = -1;
	while (++i < atio(av[1]))
	{
		filos[i].t_times.id = i + 1;
		filos[i].t_times.t_die = atoi(av[2]);
		filos[i].t_times.t_eat = atoi(av[3]);
		filos[i].t_times.t_sleep = atoi(av[4]);
		filos[i].last_meal_take = get_current_time();
		filos[i].date_init = get_current_time();
		
	}
}

int main(int argc, char **argv)
{
	t_control 	cnl;
	t_filo		filo[MAX_PHILO];
	t_sharing	forks[MAX_PHILO];

	ft_check_args(argc, argv);
	ft_init_control(&cnl, filo, forks);
	ft_init_forks(&cnl, forks, atio(argv[1]));
	ft_init_filo(&cnl, filo, forks, argv);
}
