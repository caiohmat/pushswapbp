/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:45:26 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 18:58:34 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_push(t_stk **sender, t_stk **receiver)
{
	t_stk	*temp;

	if (!*sender)
		return (1);
	temp = *sender;
	*sender = (*sender)->next;
	if (!(*receiver))
	{
		*receiver = temp;
		(*receiver)->next = NULL;
	}
	else
	{
		temp->next = *receiver;
		*receiver = temp;
	}
	return (0);
}

int	pa(t_stk **stka, t_stk **stkb)
{
	ft_putendl_fd("pa", 1);
	return (ft_push(stkb, stka));
}

int	pb(t_stk **stka, t_stk **stkb)
{
	ft_putendl_fd("pb", 1);
	return (ft_push(stka, stkb));
}
