# include "../include/philo_one.h"

void *ft_routine(void *philo)
{
    int a;

    a = 0;
    (void)philo;
    while (a < 15)
    {
        printf("%d\n", a);
        a++;
    }
    return (NULL);
}