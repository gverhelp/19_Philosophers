#include "../include/philo_one.h"

void ft_init_struct(t_struct *st)
{
    st->nbr_of_philo = 0;
    st->time_to_die = 0;
    st->time_to_eat = 0;
    st->time_to_sleep = 0;
    st->nbr_of_time_each_philo_must_eat = 0;
    st->thread = NULL;
    st->thread_time = 0;
    st->mutex = NULL;;
    st->philo_id = NULL;
    st->do_we_have_a_dead = 0;
    st->did_he_eat_enough = NULL;
    st->when_did_he_eat = NULL;
    st->ate_enough = NULL;;
    st->forks = 0;
    st->start_timer = 0;
}

void    ft_free()
{
    
}

t_struct *ft_get_my_struct(void)
{
    static t_struct st;

    return (&st);
}