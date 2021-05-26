#include "../include/philo_three.h"

void	ft_print(t_struct *st, int philo, char *str)
{
	sem_wait(st->sem_write);
	printf("%ld %d %s\n", ft_get_time(st), philo, str);
	sem_post(st->sem_write);
}

void	ft_close_sem(t_struct *st)
{
	int	a;

	a = 0;
	while (a < st->nbr_of_philo)
	{
		sem_wait(st->sem_dead);
		a++;
	}
	a = 0;
	while (a < st->nbr_of_philo)
	{
		kill(st->pid[a], SIGKILL);
		a++;
	}
}

void	ft_free(t_struct *st)
{
	free(st->pid);
}

t_struct	*ft_get_my_struct(void)
{
	static t_struct	st;

	return (&st);
}
