# include "../include/philo_one.h"

int ft_philo_is_thinking(t_struct *st, int my_philo)
{
    if (st->do_we_have_a_dead == 0)
    {
        pthread_mutex_lock(&st->write_mutex);
        printf("%ld %d is thinking\n", ft_get_time(st), my_philo + 1);
        pthread_mutex_unlock(&st->write_mutex);
    }
    return (0);
}

int ft_philo_is_eating(t_struct *st, int my_philo, int fork, int next_fork)
{
    pthread_mutex_lock(&st->mutex[fork]);
    pthread_mutex_lock(&st->mutex[next_fork]);
    if (st->do_we_have_a_dead == 0)
    {
        pthread_mutex_lock(&st->write_mutex);
        printf("%ld %d has taken a fork\n", ft_get_time(st), my_philo + 1);
        printf("%ld %d is eating\n", ft_get_time(st), my_philo + 1);
        pthread_mutex_unlock(&st->write_mutex);
        st->when_did_he_eat[my_philo] = ft_get_time(st);
        st->did_he_eat_enough[my_philo]++;
        ft_wait(st, st->time_to_eat);
    }
    pthread_mutex_unlock(&st->mutex[fork]);
    pthread_mutex_unlock(&st->mutex[next_fork]);
    return (0);
}

int ft_philo_is_sleeping(t_struct *st, int my_philo)
{
    if (st->do_we_have_a_dead == 0)
    {
        pthread_mutex_lock(&st->write_mutex);
        printf("%ld %d is sleeping\n", ft_get_time(st), my_philo + 1);
        pthread_mutex_unlock(&st->write_mutex);
        ft_wait(st, st->time_to_sleep);
    }
    return (0);
}

void    *ft_routine(void *philo)
{
    int my_philo;
    int fork;
    int next_fork;
    t_struct *st;

    st = ft_get_my_struct();
    my_philo = *(int*)philo;
    fork = my_philo;
    next_fork = (fork + 1) % st->nbr_of_philo;
    if (my_philo % 2 == 0)
    {
        next_fork = my_philo;
        fork = (next_fork + 1) % st->nbr_of_philo;
    }
    st->when_did_he_eat[my_philo] = ft_get_time(st);
    pthread_detach(*st->thread);
    while (st->do_we_have_a_dead == 0)
    {
        ft_philo_is_thinking(st, my_philo);
        ft_philo_is_eating(st, my_philo, fork, next_fork);
        ft_philo_is_sleeping(st, my_philo);
    }
    return (NULL);
}

int ft_start_philo(t_struct *st)
{
    int a;

    a = 0;
    st->start_timer = ft_get_time(st);
    pthread_create(&st->thread_time, NULL, &ft_time, NULL);
    pthread_mutex_lock(&st->dead_mutex);
    while (a < st->nbr_of_philo)
    {
        pthread_create(&st->thread[a], NULL, &ft_routine, &st->philo_id[a]);
        a++;
    }
    pthread_mutex_lock(&st->dead_mutex);
    ft_destroy_mutex(st);
    return (1);
}