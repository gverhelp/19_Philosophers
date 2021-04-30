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
    int             *did_he_eat_enough;
    int             *ate_enough;
    long int        *when_did_he_eat;
    long int        start_timer;
    pthread_t       *thread;
    pthread_t       thread_time;
    pthread_mutex_t *mutex;
    pthread_mutex_t write_mutex;
    pthread_mutex_t dead_mutex;
};

/////////// main /////////////

void ft_init_struct(t_struct *st);

/////////// parsing ////////////

int ft_parsing(t_struct *st, int argc, char **argv);
int ft_check_args(int argc, char **argv);
int ft_get_my_values(t_struct *st, char **argv);

////////// Routine /////////////

int ft_start_philo(t_struct *st);
void *ft_routine(void *philo);
int ft_philo_is_thinking(t_struct *st, int my_philo);
int ft_philo_is_eating(t_struct *st, int my_philo, int left_fork, int right_fork);
int ft_philo_is_sleeping(t_struct *st, int my_philo);

//////////// Time /////////////

void *ft_time(void *arg);
void    ft_wait(t_struct *st, int wait);
int ft_did_they_eat_enough(t_struct *st);
int ft_do_we_have_a_dead(t_struct *st);
int long ft_get_time(t_struct *st);

//////////// Init /////////////

int ft_init(t_struct *st);
int ft_init_values(t_struct *st);
int ft_init_values2(t_struct *st);
void ft_init_struct(t_struct *st);
int ft_init_threads_and_mutex(t_struct *st);

////////// Utils //////////////

t_struct *ft_get_my_struct(void);
void    ft_destroy_mutex(t_struct *st);
void    ft_free(t_struct *st);
void    ft_print(t_struct *st, int philo, char *str);

////////// libft /////////////

int	ft_atoi(const char *str);
int	ft_isdigit(char *str);
char    *ft_strdup(const char *src);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif