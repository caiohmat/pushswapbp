# include "../include/push_swap.h"

int	ft_onlynumbers(char *arg)
{
	unsigned int 	counter;

	counter = 0;
	while (arg[counter] != '\0')
	{
		if ((!ft_isdigit(arg[counter])))
		{
			if (counter != 0 || (arg[counter] != '-')
				|| (counter == 0 && arg[counter] == '-' && !arg[counter + 1]))
				return (1);
		}
		counter++;
	}
	return (0);
}

int	ft_noduplicates(char **args, int i)
{
	int	j;

	j = i + 1;
	while (args[j])
	{
		if (ft_strcmp(args[i], args[j]) == 0)
			return (1);
		j++;
	}
	return (0);
}

int	ft_overflow(char *arg)
{
	long	n;

	n = ft_atoi(arg);
	if (n > 2147483647 || n < -2147483648)
		return(1);
	return (0);
}

void	ft_isvalid(char **args)
{
	unsigned int	counter;

	counter = 0;
	while (args[counter])
	{
		if (ft_onlynumbers(args[counter]) || ft_noduplicates(args, counter)
		|| ft_overflow(args[counter]))
			ft_freeandexit(args);
		counter++;
	}
	return ;
}
