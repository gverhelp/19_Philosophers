#include "../include/philo_one.h"

int	ft_isdigit(char *str)
{
    int a;

    a = 0;
    while (str[a])
    {
	    if (str[a] < '0' || str[a] > '9')
		    return (0);
        a++;
    }
    return (1);
}