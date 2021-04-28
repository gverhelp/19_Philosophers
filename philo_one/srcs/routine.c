# include "../include/philo_one.h"

int ft_philo_is_thinking(t_struct *st, int my_philo)
{
    if (st->do_we_have_a_dead == 0)
        printf("%ld %d is thinking\n", ft_get_time(st), my_philo + 1);
    return (0);
}

int ft_philo_is_eating(t_struct *st, int my_philo)
{
    int long time;

    (void)time;
    (void)my_philo;
    time = ft_get_time(st);
    pthread_mutex_lock(&st->mutex[my_philo]);
    if (st->do_we_have_a_dead == 0)
    {
        printf("%ld %d is eating\n", ft_get_time(st), my_philo + 1);
        st->when_did_he_eat[my_philo] = ft_get_time(st);
        st->did_he_eat_enough[my_philo]++;
        ft_wait(st, st->time_to_eat);
    }
    pthread_mutex_unlock(&st->mutex[my_philo]);
    return (0);
}

int ft_philo_is_sleeping(t_struct *st, int my_philo)
{
    int long time;

    (void)time;
    (void)my_philo;
    (void)st;
    if (st->do_we_have_a_dead == 0)
    {
        printf("%ld %d is sleeping\n", ft_get_time(st), my_philo + 1);
        ft_wait(st, st->time_to_sleep);
    }
    return (0);
}

void    *ft_routine(void *philo)
{
    int my_philo;
    int forks;
    t_struct *st;

    (void)forks;
    my_philo = *(int*)philo;
    st = ft_get_my_struct();
    forks = st->nbr_of_philo;
    pthread_detach(*st->thread);
    while (st->do_we_have_a_dead == 0)
    {
        ft_philo_is_thinking(st, my_philo);
        ft_philo_is_eating(st, my_philo);
        ft_philo_is_sleeping(st, my_philo);
    }
    return (NULL);
}


/*
    pthread_mutex_lock(&st->mutex[st->forks]);
    if (st->when_did_you_eat[my_philo] - time > st->time_to_die)
    {
        st->do_we_have_a_dead = -1;
        pthread_mutex_unlock(&st->mutex[st->forks]);
        return (0);
    }
    if (st->forks >= 2)
    {
        st->forks -= 2;
        printf("%ld %d has taken a fork\n", time, my_philo);
        printf("%ld %d is eating\n", time, my_philo);
        usleep(10 * st->time_to_eat);
        st->forks +=2;
        st->when_did_you_eat[my_philo] = ft_get_time(st);
    }
    pthread_mutex_unlock(&st->mutex[st->forks]);
*/