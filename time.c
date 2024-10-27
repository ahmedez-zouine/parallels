#include "philo.h"

/*
Example 1.75 s timeout
struct timeval tv;
tv.tv_sec = 1;
tv.tv_usec = 750000;
*/

// size_t  get_current_time()
// {
//     t_timeval time;
//     if (gettimeofday(&time, NULL) != -1)
//         return (time.tv_sec * 1000 + time.tv_usec / 1000 );
// }

// size_t get_time(int code)
// {

// // }