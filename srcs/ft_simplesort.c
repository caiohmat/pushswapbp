/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:45:58 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/03 18:46:40 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_pushmin(t_stk **stka, t_stk **stkb)
{
	int	minpos;

	minpos = ft_findmin(stka);
	if (minpos + 1 == (int) ft_stklen(stka))
		rra(stka);
	else if ((int) ft_stklen(stka) - minpos == 2)
	{
		rra(stka);
		rra(stka);
	}
	else if (minpos == 1)
		ra(stka);
	else if (minpos != 0)
	{
		ra(stka);
		ra(stka);
	}
	pb(stka, stkb);
	return ;
}

static void	ft_sort3(t_stk	**stk)
{
	t_stk	*temp;
	int		minpos;

	temp = *stk;
	minpos = ft_findmin(stk);
	if (minpos == 0)
	{
		rra(stk);
		sa(stk);
	}
	else if (minpos == 1 && (temp->simple < temp->next->next->simple))
		sa(stk);
	else if (minpos == 2 && (temp->simple < temp->next->simple))
		rra(stk);
	else if (minpos == 2 && (temp->simple > temp->next->simple))
	{
		sa(stk);
		rra(stk);
	}
	else
		ra(stk);
	return ;
}

static void	ft_sort4(t_stk **stka, t_stk **stkb)
{
	ft_pushmin(stka, stkb);
	if (ft_sorted(stka))
		ft_sort3(stka);
	pa(stka, stkb);
	return ;
}

static void	ft_sort5(t_stk **stka, t_stk **stkb)
{
	ft_pushmin(stka, stkb);
	if (ft_sorted(stka))
		ft_sort4(stka, stkb);
	pa(stka, stkb);
	return ;
}

void	ft_simplesort(t_stk **stka, t_stk **stkb, unsigned int len)
{
	if (len == 2)
		sa(stka);
	else if (len == 3)
		ft_sort3(stka);
	else if (len == 4)
		ft_sort4(stka, stkb);
	else if (len == 5)
		ft_sort5(stka, stkb);
	return ;
}
