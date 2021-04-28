# include "../include/philo_one.h"

int ft_start_philo(t_struct *st)
{
    int a;

    a = 0;
    st->start_timer = ft_get_time(st);
    pthread_create(&st->thread_time, NULL, &ft_time, NULL);
    while (a < st->nbr_of_philo)
    {
        pthread_create(&st->thread[a], NULL, &ft_routine, &st->philo_id[a]);
        usleep(1000);
        a++;
    }
    ft_destroy_mutex(st);
/*    a = 0;
    while (a < st->nbr_of_philo)
    {
        st->did_he_eat_enough[a] = 4;
        a++;
    }*/
    return (1);
}