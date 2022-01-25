# include "push_swap.h"

t_stk	*ft_ascending(t_stk **stka)
{
	t_stk	*temp;
	t_stk	*lowest;

	temp = *stka;
	lowest = NULL;
	while (temp)
	{
		if ((temp->simple == -1) && (!lowest || temp->nbr < lowest->nbr))
			lowest = temp;
	}
	return (lowest);
}

void ft_simplify(t_stk **stka)
{
	t_stk	*temp;
	int		simple;

	simple = 0;
	temp = ft_ascending(stka);
	while (temp)
	{
		temp->simple = index++;
		temp = ft_ascending(stka);
	}
	return ;
}

int	ft_sorted(t_stk **stka)
{
	t_stk	*temp;

	temp = *stka;
	while (temp && temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return (1);
		temp = temp->next;
	}
	return (0);
}