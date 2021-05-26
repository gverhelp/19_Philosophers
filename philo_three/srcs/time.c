#include "../include/philo_three.h"

int long	ft_get_time(t_struct *st)
{
	struct timeval	current_time;
	int long		timer;

	gettimeofday(&current_time, NULL);
	timer = current_time.tv_sec * 1000;
	timer += current_time.tv_usec / 1000;
	return (timer - st->start_timer);
}

void	ft_wait(t_struct *st, int wait)
{
	int			a;
	long int	time_now;

	time_now = ft_get_time(st);
	a = 0;
	while (a < 10 * wait)
	{
		a++;
		if (ft_get_time(st) - time_now >= wait)
			break ;
		usleep(100);
	}
}

int	ft_do_we_have_a_dead(t_struct *st)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < st->nbr_of_philo)
	{
		if (ft_get_time(st) - st->when_did_he_eat > st->time_to_die)
		{
			st->do_we_have_a_dead = 1;
			sem_wait(st->sem_write);
			printf("%ld %d died\n", ft_get_time(st), a + 1);
			while (b < st->nbr_of_philo)
			{
				sem_post(st->sem_dead);
				b++;
			}
			return (0);
		}
		a++;
	}
	return (1);
}

void	*ft_time(void *arg)
{
	t_struct	*st;

	(void)arg;
	st = ft_get_my_struct();
	while (st->do_we_have_a_dead == 0)
	{
		if (!ft_do_we_have_a_dead(st))
			return (NULL);
		usleep(4000);
	}
	return (NULL);
}
