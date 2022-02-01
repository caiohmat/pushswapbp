# include "../include/push_swap.h"

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
		temp = temp->next;
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
		temp->simple = simple++;
		temp = ft_ascending(stka);
	}
	return ;
}
