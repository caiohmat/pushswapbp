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
t_stk	*ft_findlast(t_stk	*entry)
{
	t_stk	*lastentry;

	lastentry = entry;
	while (tempentry->next)
		tempentry = tempentry->next;
	return (lastentry);
}

void	ft_addentryback(t_stk **stk, t_stk *newentry)
{
	t_stk	*lastentry;

	if(!(*stk))
	{
		*stk = newentry;
		*stk->next = NULL;
	}
	else
	{
		lastentry = ft_findlast(*stk);
		lastentry->next = newentry;
		entry->next = NULL;
	}
}