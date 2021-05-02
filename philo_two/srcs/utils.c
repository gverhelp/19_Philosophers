#include "../include/philo_two.h"

void	ft_print(t_struct *st, int philo, char *str)
{
	sem_wait(st->sem_write);
	printf("%ld %d %s\n", ft_get_time(st), philo, str);
	sem_post(st->sem_write);
}

void	ft_close_sem(t_struct *st)
{
	int a;

	a = 0;
	while (a < st->nbr_of_philo)
	{
		pthread_detach(st->thread[a]);
		a++;
	}
	sem_close(st->sem_forks);
	sem_close(st->sem_write);
	sem_close(st->sem_dead);
}

void	ft_free(t_struct *st)
{
	free(st->ate_enough);
	free(st->philo_id);
	free(st->when_did_he_eat);
	free(st->did_he_eat_enough);
	free(st->thread);
}

t_struct	*ft_get_my_struct(void)
{
	static t_struct	st;

	return (&st);
}
