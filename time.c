#include "philo.h"

long long 	get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// void		ft_usleep(int sleeptime , t_control *mn)
// {
//     long long 	start_time;
//     struct timeval tv;

//     gettimeofday(&tv, NULL);
//     start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
//     while (1)
//     {
//         gettimeofday(&tv, NULL);
//         if (get_time() - start_time >= sleeptime)
//         break;
//         if (mn == 1)
//         {
//             gettimeofday(&tv, NULL);
//             mn->time.last_meal_take = get_time();
//             mn->is_finish = 0;
//         }
//     }
// }