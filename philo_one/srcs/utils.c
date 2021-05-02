#include "../include/philo_one.h"

void	ft_print(t_struct *st, int philo, char *str)
{
	pthread_mutex_lock(&st->write_mutex);
	printf("%ld %d %s\n", ft_get_time(st), philo, str);
	pthread_mutex_unlock(&st->write_mutex);
}

void	ft_destroy_mutex(t_struct *st)
{
	int	a;

	a = 0;
	while (a < st->nbr_of_philo)
	{
		pthread_detach(st->thread[a]);
		pthread_mutex_destroy(&st->mutex[a]);
		a++;
	}
	pthread_mutex_destroy(&st->write_mutex);
	pthread_mutex_destroy(&st->dead_mutex);
}

void	ft_free(t_struct *st)
{
	free(st->ate_enough);
	free(st->philo_id);
	free(st->when_did_he_eat);
	free(st->did_he_eat_enough);
	free(st->thread);
	free(st->mutex);
}

t_struct	*ft_get_my_struct(void)
{
	static t_struct	st;

	return (&st);
}
