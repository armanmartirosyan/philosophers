
#include "philosophers.h"

void	force_quit(void)
{
	write(1, "Malloc Error!\n", 14);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}
 void    *free_single(void **addr)
 {
     if (*addr)
     {
         free (*addr);
         *addr = 0;
     }
     return (0);
 }
 
void	*free_double(void ***addr)
{
    int i;

    i = 0;
    if (*addr)
    {
        while ((*addr)[i])
        {
            free_single((void *)&(*addr)[i]);
            i++;
        }
        free_single((void *)&(*addr));
    }
    return (0);
}