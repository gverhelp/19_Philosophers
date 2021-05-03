#include "../include/philo_two.h"

int	ft_philo_is_thinking(t_struct *st, int my_philo)
{
	if (st->do_we_have_a_dead == 0)
		ft_print(st, my_philo + 1, "is thinking");
	return (0);
}

int	ft_philo_is_eating(t_struct *st, int my_philo)
{
	if (st->do_we_have_a_dead == 0)
	{
		st->when_did_he_eat[my_philo] = ft_get_time(st);
		st->did_he_eat_enough[my_philo]++;
		ft_print(st, my_philo + 1, "has taken a fork");
		ft_print(st, my_philo + 1, "is eating");
		ft_wait(st, st->time_to_eat);
	}
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
	t_struct	*st;

	st = ft_get_my_struct();
	my_philo = *(int *)philo;
	st->when_did_he_eat[my_philo] = ft_get_time(st);
	while (st->do_we_have_a_dead == 0)
	{
		ft_philo_is_thinking(st, my_philo);
		sem_wait(st->sem_forks);
		sem_wait(st->sem_forks);
		ft_print(st, my_philo + 1, "has taken a fork");
		ft_philo_is_eating(st, my_philo);
		sem_post(st->sem_forks);
		sem_post(st->sem_forks);
		ft_philo_is_sleeping(st, my_philo);
	}
	return (NULL);
}

int	ft_start_philo(t_struct *st)
{
	int	a;

	a = 0;
	st->start_timer = ft_get_time(st);
	sem_wait(st->sem_dead);
	pthread_create(&st->thread_time, NULL, &ft_time, NULL);
	while (a < st->nbr_of_philo)
	{
		pthread_create(&st->thread[a], NULL, &ft_routine, &st->philo_id[a]);
		a++;
	}
	sem_wait(st->sem_dead);
	ft_close_sem(st);
	return (1);
}
