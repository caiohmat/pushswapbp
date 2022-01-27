# include "../include/push_swap.h"

t_stk	*ft_createentry(int nbr)
{
	t_stk	*entry;

	entry = (t_stk *) malloc(sizeof(*entry));
	if (!entry)
		return (NULL);
	entry->nbr = nbr;
	entry->simple = -1;
	entry->next = NULL;
	return (entry);
}
t_stk	*ft_findlast(t_stk	*entry)
{
	t_stk	*lastentry;

	lastentry = entry;
	while (lastentry->next)
		lastentry = lastentry->next;
	return (lastentry);
}

void	ft_addentryback(t_stk **stk, t_stk *newentry)
{
	t_stk	*lastentry;


	printf("tt:%d\n", newentry->nbr);
	if(*stk)
	{
		lastentry = ft_findlast(*stk);
		lastentry->next = newentry;
	}
	else
	{
		*stk = newentry;
		(*stk)->next = NULL;;
	}
}

void	ft_stackstart(t_stk **stka, char **args)
{
	t_stk	*entry;
	unsigned int	counter;

	counter = 0;
	while (args[counter])
	{
		entry = ft_createentry(ft_atoi(args[counter]));
		ft_addentryback(stka, entry);
		counter++;
	}
	ft_freeptr(args);
	printf("%s\n", "teste123");
	ft_simplify(stka);
	return ;
}

int	ft_stklen(t_stk **stk)
{
	t_stk	*temp;
	unsigned int	len;

	temp = *stk;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}