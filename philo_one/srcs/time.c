#include "../include/philo_one.h"

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

int	ft_did_they_eat_enough(t_struct *st)
{
	int	a;
	int	they_all_ate_enough;

	a = -1;
	they_all_ate_enough = 0;
	while (++a < st->nbr_of_philo)
	{
		if (st->did_he_eat_enough[a] == st->nbr_of_time_each_philo_must_eat)
			st->ate_enough[a] = 1;
	}
	a = -1;
	while (++a < st->nbr_of_philo)
	{
		if (st->ate_enough[a] == 1)
			they_all_ate_enough++;
	}
	if (they_all_ate_enough == st->nbr_of_philo)
	{
		st->do_we_have_a_dead = 1;
//      pthread_mutex_lock(&st->write_mutex);
		pthread_mutex_unlock(&st->dead_mutex);
		return (0);
	}
	return (1);
}

int	ft_do_we_have_a_dead(t_struct *st)
{
	int	a;

	a = 0;
	while (a < st->nbr_of_philo)
	{
		if (ft_get_time(st) - st->when_did_he_eat[a] > st->time_to_die)
		{
			st->do_we_have_a_dead = 1;
			ft_print(st, a + 1, "died");
			pthread_mutex_unlock(&st->dead_mutex);
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
		if (st->nbr_of_time_each_philo_must_eat > 0)
			if (!ft_did_they_eat_enough(st))
				return (NULL);
		if (!ft_do_we_have_a_dead(st))
			return (NULL);
		usleep(4000);
	}
	return (NULL);
}
