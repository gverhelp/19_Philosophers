#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_struct t_struct;

struct              s_struct
{
    int             nbr_of_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             nbr_of_time_each_philo_must_eat;
    int             *philo_id;
    int             do_we_have_a_dead;
    long int        *when_did_you_eat;
    int             forks;
    long int        timer;
    pthread_t       *thread;
    pthread_t       thread_time;
    pthread_mutex_t *mutex;
};

/////////// main /////////////

void ft_init_struct(t_struct *st);

/////////// parsing ////////////

int ft_parsing(t_struct *st, int argc, char **argv);
int ft_checkargs(int argc, char **argv);
int ft_get_my_values(t_struct *st, char **argv);
int ft_give_philo_id(t_struct *st);

////////// Start philo ////////

int ft_start_philo(t_struct *st);
int ft_init_threads(t_struct *st);

////////// Routine /////////////

void *ft_routine(void *philo);
int ft_philo_is_thinking(t_struct *st, int my_philo);
int ft_philo_is_eating(t_struct *st, int my_philo);
int ft_philo_is_sleeping(t_struct *st, int my_philo);


//////////// Time /////////////

void *ft_time(void *arg);
int long ft_get_time(t_struct *st);

////////// Utils //////////////

void ft_init_struct(t_struct *st);
t_struct *ft_get_my_struct(void);

////////// libft /////////////

int	ft_atoi(const char *str);
int	ft_isdigit(char *str);

#endif