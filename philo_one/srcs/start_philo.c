# include "../include/philo_one.h"

int ft_init_threads(t_struct *st)
{
    st->thread = malloc(sizeof(pthread_t) * st->nbr_of_philo);
    if (!st->thread)
        return (0);
    return (1);
}

int ft_start_philo(t_struct *st)
{
    int a;

    a = 0;
    if (!ft_init_threads(st))
        return (0);
    while (a < st->nbr_of_philo)
    {
        pthread_create(&st->thread[a], NULL, &ft_routine, &st->philo_id[a]);
        usleep(4000);
        a++;
    }
    return (1);
}