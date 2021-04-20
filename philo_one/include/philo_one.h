#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_struct t_struct;

struct          s_struct
{
    int         nbr_of_philo;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         nbr_of_time_each_philo_must_eat;
};

/////////// main /////////////

void ft_init_struct(t_struct *st);

/////////// parsing ////////////

int ft_parsing(t_struct *st, int argc, char **argv);
int ft_checkargs(int argc, char **argv);
int ft_get_my_values(t_struct *st, char **argv);

////////// Utils //////////////

int	ft_isdigit(char *str);

////////// libft /////////////

int	ft_atoi(const char *str);

#endif