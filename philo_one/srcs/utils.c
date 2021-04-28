#include "../include/philo_one.h"

void ft_init_struct(t_struct *st)
{
    st->nbr_of_philo = 0;
    st->time_to_die = 0;
    st->time_to_eat = 0;
    st->time_to_sleep = 0;
    st->nbr_of_time_each_philo_must_eat = 0;
    st->philo_id = NULL;
    st->do_we_have_a_dead = 0;
    st->did_he_eat_enough = NULL;
    st->when_did_he_eat = NULL;
    st->ate_enough = NULL;;
    st->start_timer = 0;
}

void    ft_destroy_mutex(t_struct *st)
{
    int a;

    a = 0;
    while (a < st->nbr_of_philo)
    {
        pthread_mutex_destroy(&st->mutex[a]);
        a++;
    }
}

void    ft_free()
{
    
}

t_struct *ft_get_my_struct(void)
{
    static t_struct st;

    return (&st);
}