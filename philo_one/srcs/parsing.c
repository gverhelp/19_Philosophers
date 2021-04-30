#include "../include/philo_one.h"

int	ft_check_args(int argc, char **argv)
{
	int	a;

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

int	ft_get_my_values(t_struct *st, char **argv)
{
	st->nbr_of_philo = ft_atoi(argv[1]);
	if (st->nbr_of_philo < 2)
		return (0);
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

int	ft_parsing(t_struct *st, int argc, char **argv)
{
	if (!ft_check_args(argc, argv))
		return (0);
	if (!ft_get_my_values(st, argv))
	{
		write(2, "Invalid arguments\n", 18);
		return (0);
	}
	return (1);
}
