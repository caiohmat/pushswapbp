# include "../include/push_swap.h"

void	ft_sort3(t_stk	**stka)
{
	t_stk	*temp;

	temp = *stka;
	if (temp->simple == 0)
	{
		rra(stka);
		sa(stka);
	}
	else if (temp->simple == 1 && temp->next->simple = 0)
		sa(stka);
	else if (temp->simple == 1 && temp->next->simple = 2)
		rra(stka);
	else if (temp->simple == 2 && temp->next->simple = 1)
	{
		sa(stka);
		rra(stka);
	}
	else
		ra(stka);
}

void	ft_simplesort(t_stk **stka, t_stk **stkb, int len)
{
	if (len == 2)
		sa(stka);
	else if (len == 3)
		ft_sort3(stka);
}