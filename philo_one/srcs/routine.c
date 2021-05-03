#include "../include/philo_one.h"

int	ft_philo_is_thinking(t_struct *st, int my_philo)
{
	if (st->do_we_have_a_dead == 0)
		ft_print(st, my_philo + 1, "is thinking");
	return (0);
}

int	ft_philo_is_eating(t_struct *st, int my_philo,
	int left_fork, int right_fork)
{
	pthread_mutex_lock(&st->mutex[left_fork]);
	ft_print(st, my_philo + 1, "has taken a fork");
	pthread_mutex_lock(&st->mutex[right_fork]);
	if (st->do_we_have_a_dead == 0)
	{
		st->when_did_he_eat[my_philo] = ft_get_time(st);
		st->did_he_eat_enough[my_philo]++;
		ft_print(st, my_philo + 1, "has taken a fork");
		ft_print(st, my_philo + 1, "is eating");
		ft_wait(st, st->time_to_eat);
	}
	pthread_mutex_unlock(&st->mutex[left_fork]);
	pthread_mutex_unlock(&st->mutex[right_fork]);
	return (0);
}

int	ft_philo_is_sleeping(t_struct *st, int my_philo)
{
	if (st->do_we_have_a_dead == 0)
	{	
		ft_print(st, my_philo + 1, "is sleeping");
		ft_wait(st, st->time_to_sleep);
	}
	return (0);
}

void	*ft_routine(void *philo)
{
	int			my_philo;
	int			left_fork;
	int			right_fork;
	t_struct	*st;

	st = ft_get_my_struct();
	my_philo = *(int *)philo;
	left_fork = my_philo;
	right_fork = (left_fork + 1) % st->nbr_of_philo;
	if (my_philo % 2 == 0)
	{
		right_fork = my_philo;
		left_fork = (right_fork + 1) % st->nbr_of_philo;
	}
	st->when_did_he_eat[my_philo] = ft_get_time(st);
	while (st->do_we_have_a_dead == 0)
	{
		ft_philo_is_thinking(st, my_philo);
		ft_philo_is_eating(st, my_philo, left_fork, right_fork);
		ft_philo_is_sleeping(st, my_philo);
	}
	return (NULL);
}

int	ft_start_philo(t_struct *st)
{
	int	a;

	a = 0;
	st->start_timer = ft_get_time(st);
	pthread_mutex_lock(&st->dead_mutex);
	pthread_create(&st->thread_time, NULL, &ft_time, NULL);
	while (a < st->nbr_of_philo)
	{
		pthread_create(&st->thread[a], NULL, &ft_routine, &st->philo_id[a]);
		a++;
	}
	pthread_mutex_lock(&st->dead_mutex);
	ft_destroy_mutex(st);
	return (1);
}
