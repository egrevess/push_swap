#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long int	i;
	size_t		nb;
	long int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1 * neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = str[i] + (nb * 10) - 48;
		i++;
	}
	if (nb >= 9223372036854775807 && neg == 1)
		nb = -1;
	else if (nb > 9223372036854775807 && neg == -1)
		nb = 0;
	return (nb * neg);
}
