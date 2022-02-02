/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:45:58 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 18:45:59 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

static void	ft_pushmin(t_stk **stka, t_stk **stkb, int min)
{
	int	minpos;

	minpos = ft_findmin(stka, min);
	if (minpos + 1 == ft_stklen(stka))
		rra(stka);
	else if (ft_stklen(stka) - minpos == 2)
	{
		rra(stka);
		rra(stka);
	}
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

	temp = *stk;
	if (temp->simple == 0)
	{
		rra(stk);
		sa(stk);
	}
	else if (temp->simple == 1 && temp->next->simple == 0)
		sa(stk);
	else if (temp->simple == 1 && temp->next->simple == 2)
		rra(stk);
	else if (temp->simple == 2 && temp->next->simple == 1)
	{
		sa(stk);
		rra(stk);
	}
	else
		ra(stk);
	return ;
}

static void	ft_sort5(t_stk **stka, t_stk **stkb)
{
	t_stk	*temp;
	int		min;

	min = 0;
	while (*stka && ft_sorted(stka))
	{
		temp = *stka;
		if (temp->simple > temp->next->simple)
			sa(stka);
		if (ft_sorted(stka))
			ft_pushmin(stka, stkb, min);
		min++;
	}
	while (*stkb)
		pa(stka, stkb);
	return ;
}

void	ft_simplesort(t_stk **stka, t_stk **stkb, int len)
{
	if (len == 2)
		sa(stka);
	else if (len == 3)
		ft_sort3(stka);
	else if (len <= 5)
		ft_sort5(stka, stkb);
	return ;
}
