# include "../include/push_swap.h"

static int	ft_push(t_stk **sender, t_stk **receiver)
{
	t_stk	*tsend;
	t_stk	*trec;
	t_stk	*temp;

	if (!*sender)
		return (0);
	trec = *receiver;
	tsend = *sender;
	temp = tsend;
	tsend = tsend->next;
	*sender = tsend;
	if (!trec)
	{
		trec = temp;
		trec->next = NULL;
		*receiver = trec;
	}
	else
	{
		temp->next = trec;
		*receiver = temp;
	}
	return (1);
}

int pa(t_stk **stka, t_stk **stkb)
{
	ft_putendl_fd("pa", 1);
	return (ft_push(stkb, stka));
}

int pb(t_stk **stka, t_stk **stkb)
{
	ft_putendl_fd("pb", 1);
	return (ft_push(stka, stkb));
}
