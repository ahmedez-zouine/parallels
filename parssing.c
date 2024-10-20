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
    while (str[j] == '  ' && str[j] != '\0')
        j++;
    while (str[j])
    {
        result = result * 10 + (str[j] -  '0');
        j++;      
    }
    return result;
}