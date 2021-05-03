#include "../include/philo_two.h"

void	ft_init_struct(t_struct *st)
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
	st->ate_enough = NULL;
	st->start_timer = 0;
}

int	ft_init_values2(t_struct *st)
{
	int	a;

	a = 0;
	st->when_did_he_eat = (long int *)malloc(sizeof(long int)
			* st->nbr_of_philo);
	if (!st->when_did_he_eat)
		return (0);
	while (a < st->nbr_of_philo)
	{
		st->when_did_he_eat[a] = 0;
		a++;
	}
	st->ate_enough = (int *)malloc(sizeof(int) * st->nbr_of_philo);
	if (!st->ate_enough)
		return (0);
	a = 0;
	while (a < st->nbr_of_philo)
	{
		st->ate_enough[a] = 0;
		a++;
	}
	return (1);
}

int	ft_init_values(t_struct *st)
{
	int	a;

	a = 0;
	st->philo_id = (int *)malloc(sizeof(int) * st->nbr_of_philo);
	if (!st->philo_id)
		return (0);
	while (a < st->nbr_of_philo)
	{
		st->philo_id[a] = a;
		a++;
	}
	st->did_he_eat_enough = (int *)malloc(sizeof(int) * st->nbr_of_philo);
	if (!st->did_he_eat_enough)
		return (0);
	a = 0;
	while (a < st->nbr_of_philo)
	{
		st->did_he_eat_enough[a] = 0;
		a++;
	}
	return (ft_init_values2(st));
}

int	ft_init_threads_and_sem(t_struct *st)
{
	st->thread = malloc(sizeof(pthread_t) * st->nbr_of_philo);
	if (!st->thread)
		return (0);
	memset(st->thread, 0, st->nbr_of_philo * 8);
	sem_unlink("sem_forks");
	st->sem_forks = sem_open("sem_forks", O_CREAT, 0644, st->nbr_of_philo);
	if (st->sem_forks == SEM_FAILED)
		return (0);
	sem_unlink("sem_write");
	st->sem_write = sem_open("sem_write", O_CREAT, 0644, 1);
	if (st->sem_write == SEM_FAILED)
		return (0);
	sem_unlink("sem_dead");
	st->sem_dead = sem_open("sem_dead", O_CREAT, 0644, 1);
	if (st->sem_dead == SEM_FAILED)
		return (0);
	return (1);
}

int	ft_init(t_struct *st)
{
	if (!ft_init_values(st))
		return (0);
	if (!ft_init_threads_and_sem(st))
		return (0);
	return (1);
}
