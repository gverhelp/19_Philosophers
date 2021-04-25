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

static int	ft_islong(int sign, unsigned long int value)
{
	if (sign == -1 && value == 2147483648)
		return (value *sign);
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = ((value * 10) + (str[i] - 48));
		i++;
	}
	if (value >= 2147483648)
		return (ft_islong(sign, value));
	return (value * sign);
}