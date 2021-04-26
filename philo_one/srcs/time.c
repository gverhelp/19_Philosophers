# include "../include/philo_one.h"

int long ft_get_time(t_struct *st)
{
    struct timeval current_time;
    int long    timer;

    gettimeofday(&current_time, NULL);
    timer = current_time.tv_sec * 1000;
    timer += current_time.tv_usec / 1000;
    return (timer - st->start_timer);
}

int ft_did_they_eat_enough(t_struct *st)
{
    int a;
    int they_all_ate_enough;

    a = 0;
    they_all_ate_enough = 0;
    while (a < st->nbr_of_philo)
    {
        if (st->did_he_eat_enough[a] == st->nbr_of_time_each_philo_must_eat)
            st->ate_enough[a] = 1;
        a++;
    }
    a = 0;
    while (a < st->nbr_of_philo)
    {
        if (st->ate_enough[a] == 1)
            they_all_ate_enough++;
        a++;
    }
    if (they_all_ate_enough == st->nbr_of_philo)
    {
        printf("Assez mangé!\n");
        st->do_we_have_a_dead = 1;
        return (0);
    }
    return (1);
}

int ft_do_we_have_a_dead(t_struct *st)
{
    int a;

    a = 0;
    while (a < st->nbr_of_philo)
    {
        if (ft_get_time(st) - st->when_did_he_eat[a] >= st->time_to_die)
        {
            st->do_we_have_a_dead = 1;
            printf("%ld %d died\n", ft_get_time(st), a + 1);
            return (0);
        }
        a++;
    }
    return (1);
}

void    *ft_time(void *arg)
{
    t_struct *st;

    (void)arg;
    st = ft_get_my_struct();
    while (st->do_we_have_a_dead == 0)
    {
        if (!ft_did_they_eat_enough(st))
            return (NULL);
        if (!ft_do_we_have_a_dead(st))
            return (NULL);
    }
    return (NULL);
}