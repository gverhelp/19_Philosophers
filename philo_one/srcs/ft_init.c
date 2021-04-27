#include "../include/philo_one.h"

int ft_init_values2(t_struct *st)
{
    int a;

    a = 0;
    st->when_did_he_eat = (long int *)malloc(sizeof(long int) * st->nbr_of_philo);
    if (!st->when_did_he_eat)
        return (0);
    while (a < st->nbr_of_philo)
    {
        st->when_did_he_eat[a] = 0;
        a++;
    }
    st->ate_enough = (int*)malloc(sizeof(int) * st->nbr_of_philo);
    if (!st->ate_enough)
        return (0);
    a = 0;
    while (a < st->nbr_of_philo)
    {
        st->ate_enough[a] = 0;
        a++;
    }
    return (1);
}

int ft_init_values(t_struct *st)
{
    int a;

    a = 0;
    st->philo_id = (int*)malloc(sizeof(int) * st->nbr_of_philo);
    if (!st->philo_id)
        return (0);
    while (a < st->nbr_of_philo)
    {
        st->philo_id[a] = a + 1;
        a++;
    }
    st->did_he_eat_enough = (int*)malloc(sizeof(int) * st->nbr_of_philo);
    if (!st->did_he_eat_enough)
        return (0);
    a = 0;
    while (a < st->nbr_of_philo)
    {
        st->did_he_eat_enough[a] = 0;
        a++;
    }
    return (ft_init_values2(st));
}

int ft_init_threads_and_mutex(t_struct *st)
{
    int a;

    a = 0;
    st->thread = malloc(sizeof(pthread_t) * st->nbr_of_philo);
    if (!st->thread)
        return (0);
    st->mutex = malloc (sizeof(pthread_mutex_t) * st->nbr_of_philo);
    if (!st->mutex)
        return (0);
    while (a < st->nbr_of_philo)
    {
        pthread_mutex_init(&st->mutex[a], NULL);
        a++;
    }
    return (1);
}

int ft_init(t_struct *st)
{
    if (!ft_init_values(st))
        return (0);
    if (!ft_init_threads_and_mutex(st))
        return (0);
    return (1);
}