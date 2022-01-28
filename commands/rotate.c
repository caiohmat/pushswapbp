# include "../include/push_swap.h"

static int	ft_rotate(t_stk **stk)
{
	t_stk	*temp;
	t_stk	*last;

	if (!(*stk && (*stk)->next))
		return (1);
	temp = *stk;
	*stk = (*stk)->next;
	last = ft_findlast(*stk);
	last->next = temp;
	temp->next = NULL;
	return (0);
}

int	ra(t_stk **stka)
{
	ft_putendl_fd("ra", 1);
	return (ft_rotate(stka));
}

int	rb(t_stk **stkb)
{
	ft_putendl_fd("rb", 1);
	return (ft_rotate(stkb));
}

int rr(t_stk **stka, t_stk **stkb)
{
	ft_putendl_fd("rr", 1);
	return (ft_rotate(stka) + ft_rotate(stkb));
}
