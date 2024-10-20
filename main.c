#include "philo.h"

int check_isdisgit(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }   
    return 1;
}

long str_to_long(char *str)
{
    long result = 0;
    int j = 0;
    while (str[j] == ' ' && str[j] != '\0')
        j++;
    while (str[j])
    {
        result = result * 10 + (str[j] -  '0');
        j++;      
    }
    return result;
}

int ft_init_data(t_data *data, int argc, char **argv)
{
    int i = 0;
    if(argc > i)
    {
        data->number_of_philosophers = str_to_long(argv[1]);
        data->time_to_die = str_to_long(argv[2]);
        data->time_to_eat = str_to_long(argv[3]);
        data->time_to_sleep = str_to_long(argv[4]);
        // if (argc > 4)
        //     data->number_of_times_each_philosopher_must_eat = str_to_long(argv[5]);
        // else
        //     data->number_of_times_each_philosopher_must_eat = -1;
    }
}

void ft_printf_data(t_data *data)
{
    printf("number of philo %ld\n", data->number_of_philosophers);
    printf("time to die of philo %ld\n", data->time_to_eat);
    printf("time of eating %ld\n", data->time_to_eat);
    printf("time of sleeping %ld\n", data->time_to_sleep);
    if(data->number_of_times_each_philosopher_must_eat != -1)
        printf("%ld number_of_times_each_philosopher_must_eat\n",data->number_of_times_each_philosopher_must_eat);
}

int main(int argc, char **argv)
{
    t_philo *philo;
    if  (argc != 5 && argc != 4)
    {
        printf("Error: wrong number of arguments\n");
        return (1);
    }
    printf("%ld\n", str_to_long(argv[1]));
    printf("%ld\n", str_to_long(argv[2]));
    printf("%ld\n", str_to_long(argv[3]));
    philo = malloc(sizeof(t_philo));
    if (philo == NULL)
        printf("Error malloc");
    printf("Hello\n");
    ft_init_data(philo->data, argc, argv);
    printf("Words\n");
    ft_printf_data(philo->data);
    printf("from Me\n");
}
