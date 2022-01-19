# include "push_swap.h"

void	ft_freeptr(char **args)
{
	unsigned int 	counter;

	counter = 0;
	while (args[counter])
	{
		free(args[counter]);
		counter++;
	}
	free(args);
	return ;
}

void	ft_freeandexit(char **args, int exitnbr)
{
	ft_freeptr(args);
	ft_putstr_fd("Error\n", 2);
	exit (exitnbr);
}
