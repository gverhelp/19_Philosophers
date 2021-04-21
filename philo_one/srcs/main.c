#include "../include/philo_one.h"

void ft_init_struct(t_struct *st)
{
    st->nbr_of_philo = 0;
    st->time_to_die = 0;
    st->time_to_eat = 0;
    st->time_to_sleep = 0;
    st->nbr_of_time_each_philo_must_eat = 0;
    st->philo_id = NULL;
    st->istheend = 0;
}

int main(int argc, char **argv)
{
    t_struct    st;

    ft_init_struct(&st);
    if (!ft_parsing(&st, argc, argv))
        return (0);
    if (!ft_start_philo(&st))
        return (0);
    return (0);
}