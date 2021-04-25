# include "../include/philo_one.h"

int long ft_get_time(t_struct *st)
{
    struct timeval current_time;
    int long    timer;

    gettimeofday(&current_time, NULL);
    timer = current_time.tv_sec * 1000;
    timer += current_time.tv_usec / 1000;
    return (timer - st->timer);
}

void    *ft_time(void *arg)
{
    (void)arg;
    return (NULL);
}