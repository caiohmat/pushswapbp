/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:45:29 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 18:57:48 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_reverse(t_stk **stk)
{
	t_stk	*temp;
	t_stk	*temp2;
	t_stk	*last;

	if (!(*stk && (*stk)->next))
		return (1);
	temp = *stk;
	while (temp && temp->next)
	{
		if (temp->next->next == NULL)
			temp2 = temp;
		temp = temp->next;
	}
	last = ft_findlast(*stk);
	temp = *stk;
	*stk = last;
	(*stk)->next = temp;
	temp2->next = NULL;
	return (0);
}

int	rra(t_stk **stka)
{
	ft_putendl_fd("rra", 1);
	return (ft_reverse(stka));
}

int	rrb(t_stk **stkb)
{
	ft_putendl_fd("rrb", 1);
	return (ft_reverse(stkb));
}

int	rrr(t_stk **stka, t_stk **stkb)
{
	ft_putendl_fd("rrr", 1);
	return (ft_reverse(stka) + ft_reverse(stkb));
}
