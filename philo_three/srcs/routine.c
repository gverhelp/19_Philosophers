#include "../include/philo_three.h"

int	ft_philo_is_thinking(t_struct *st)
{
	if (st->do_we_have_a_dead == 0)
		ft_print(st, st->my_philo, "is thinking");
	return (0);
}

int	ft_philo_is_eating(t_struct *st)
{
	if (st->do_we_have_a_dead == 0)
	{
		st->when_did_he_eat = ft_get_time(st);
		st->did_he_eat_enough++;
		ft_print(st, st->my_philo, "has taken a fork");
		ft_print(st, st->my_philo, "is eating");
		if (st->nbr_of_time_each_philo_must_eat > 0)
		{
			if (st->did_he_eat_enough == st->nbr_of_time_each_philo_must_eat)
			{
				st->do_we_have_a_dead = 1;
				sem_post(st->sem_ate);
			}
		}
		ft_wait(st, st->time_to_eat);
	}
	return (0);
}

int	ft_philo_is_sleeping(t_struct *st)
{
	if (st->do_we_have_a_dead == 0)
	{	
		ft_print(st, st->my_philo, "is sleeping");
		ft_wait(st, st->time_to_sleep);
	}
	return (0);
}

int	ft_routine(void)
{
	t_struct	*st;

	st = ft_get_my_struct();
	st->when_did_he_eat = ft_get_time(st);
	while (st->do_we_have_a_dead == 0)
	{
		ft_philo_is_thinking(st);
		sem_wait(st->sem_forks);
		sem_wait(st->sem_forks);
		ft_print(st, st->my_philo, "has taken a fork");
		ft_philo_is_eating(st);
		sem_post(st->sem_forks);
		sem_post(st->sem_forks);
		if (st->do_we_have_a_dead == 1)
		{
			ft_free(st);
			exit(0);
		}
		ft_philo_is_sleeping(st);
	}
	return (1);
}

int	ft_start_philo(t_struct *st)
{
	int	a;

	a = 0;
	st->start_timer = ft_get_time(st);
	while (a < st->nbr_of_philo)
	{
		sem_wait(st->sem_ate);
		a++;
	}
	a = 0;
	while (a < st->nbr_of_philo)
	{
		st->pid[a] = fork();
		st->my_philo = a + 1;
		if (st->pid[a] == 0)
		{
			pthread_create(&st->thread_time, NULL, &ft_time, NULL);
			ft_routine();
		}
		a++;
	}
	ft_close_sem(st);
	return (1);
}
