static int	ft_swap(t_stk **stk)
{
	int	temp;

	if (*stk && *stk->next)
	{
		temp = *stk->nbr;
		*stk->nbr = *stk->next->nbr;
		*stk->next->nbr = temp;
		temp = *stk->index;
		*stk->index = *stk->next->index;
		*stk->next->index = temp;
		return (0);
	}
	return (1);
}

int	sa(t_stk **stka)
{
	ft_putendl_fd("sa", 1);
	return (ft_swap(stka));
}

int	sb(t_stk **stkb)
{
	ft_putendl_fd("sb", 1);
	return (ft_swap(stkb));
}

int ss(t_stk **stka, t_stk **stkb)
{
	ft_putendl_fd("ss", 1);
	return (ft_swap(stka) + ft_swap(stkb));
}
