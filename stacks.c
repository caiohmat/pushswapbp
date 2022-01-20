# include "push_swap.h"

t_stk	**ft_stackstart(t_stk **stka, char **args)
{
	t_stk	*entry;
	unsigned int	counter;

	counter = 0;
	while (args[counter])
	{
		entry = ft_createentry(ft_atoi(args[counter]))
		ft_addentryback(stka, entry);
		counter;
	}
	ft_freeptr(args);
	return ;
}

t_stk	*createentry(int nbr)
{
	t_stk	*entry;

	entry = malloc(sizeof(*new));
	if (!entry)
		return (NULL);
	entry->nbr = nbr;
	entry->next = NULL;
	return (entry);
}

void	ft_addentryback(t_stk **stk, t_stk *entry)
{
	
}