#include "../include/philo_one.h"

int ft_checkargs(int argc, char **argv)
{
    int a;

    a = 1;
    if (argc < 5)
    {
        write(2, "Not enough arguments\n", 21);
        return (0);
    }
    if (argc > 6)
    {
        write(2, "Too many arguments\n", 19);
        return (0);
    }
    while (a < argc)
    {
        if (!ft_isdigit(argv[a]))
        {
            write(2, "Invalid arguments\n", 18);
            return (0);
        }
        a++;
    }
    return (1);
}

int ft_get_my_values(t_struct *st, char **argv)
{
    st->nbr_of_philo = ft_atoi(argv[1]);
    if (st->nbr_of_philo < 2)
        return (0);
    st->forks = st->nbr_of_philo;
    st->time_to_die = ft_atoi(argv[2]);
    if (st->time_to_die < 0)
        return (0);
    st->time_to_eat = ft_atoi(argv[3]);
    if (st->time_to_eat < 0)
        return (0);
    st->time_to_sleep = ft_atoi(argv[4]);
    if (st->time_to_eat < 0)
        return (0);
    if (argv[5])
        st->nbr_of_time_each_philo_must_eat = ft_atoi(argv[5]);
    else
        st->nbr_of_time_each_philo_must_eat = 0;
    return (1);
}

int ft_give_philo_id(t_struct *st)
{
    int a;

    a = 0;
    st->philo_id = malloc(sizeof(int) * st->nbr_of_philo);
    if (!st->philo_id)
        return (0);
    while (a < st->nbr_of_philo)
    {
        st->philo_id[a] = a + 1;
        a++;
    }
    st->when_did_you_eat = (long int *)malloc(sizeof(long int) * st->nbr_of_philo);
    if (!st->when_did_you_eat)
        return (0);
    a = 0;
    while (a < st->nbr_of_philo)
    {
        st->when_did_you_eat[a] = 0;
        a++;
    }
    return (1);
}

int ft_parsing(t_struct *st, int argc, char **argv)
{
    if (!ft_checkargs(argc, argv))
        return (0);
    if (!ft_get_my_values(st, argv))
    {
        write(2, "Invalid arguments\n", 18);
        return (0);
    }
    if (!ft_give_philo_id(st))
        return (0);
    return (1);
}