#include "../include/philo_two.h"

int	main(int argc, char **argv)
{
	t_struct	*st;

	st = ft_get_my_struct();
	ft_init_struct(st);
	if (!ft_parsing(st, argc, argv))
		return (0);
	if (!ft_init(st))
		return (0);
	if (!ft_start_philo(st))
		return (0);
	ft_free(st);
	return (0);
}
