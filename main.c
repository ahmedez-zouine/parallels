/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:42:25 by aez-zoui          #+#    #+#             */
/*   Updated: 2024/11/02 21:42:27 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 0;
	if (argc < 5 || argc > 6)
		error_message("[Argument Count ERROR]\n", 1);
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > MAX_FILO))
			error_message("[Argument ERROR]\n", 1);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			error_message("[Argument ERROR]\n", 1);
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			error_message("[Argument ERROR]\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_philo			philos[MAX_FILO];
	pthread_mutex_t	forks[MAX_FILO];
	t_engine		engine;

	check_args(argc, argv);
	init_engine(&engine, philos, forks);
	init_forks(&engine, forks, ft_atoi(argv[1]));
	init_philos(&engine, philos, forks, argv);
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, NULL, philos[0].philo_count, 0);
	return (0);
}
