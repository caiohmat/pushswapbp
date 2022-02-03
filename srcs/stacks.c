/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:46:07 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/03 17:36:14 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*ft_createentry(int nbr)
{
	t_stk	*entry;

	entry = malloc(sizeof(*entry));
	if (!entry)
		return (NULL);
	entry->nbr = nbr;
	entry->simple = 0;
	entry->started = 0;
	entry->next = NULL;
	return (entry);
}

t_stk	*ft_findlast(t_stk	*entry)
{
	t_stk	*lastentry;

	lastentry = entry;
	while (lastentry->next)
		lastentry = lastentry->next;
	return (lastentry);
}

int	ft_findmin(t_stk **stka)
{
	t_stk				*temp;
	int					counter;
	int					position;
	unsigned int		min;

	counter = 0;
	position = 0;
	temp = *stka;
	min = temp->simple;
	while (temp)
	{
		if (temp->simple < min)
		{
			position = counter;
			min = temp->simple;
		}
		counter++;
		temp = temp->next;
	}
	return (position);
}

void	ft_addentryback(t_stk **stk, t_stk *newentry)
{
	t_stk	*lastentry;

	if (*stk)
	{
		lastentry = ft_findlast(*stk);
		lastentry->next = newentry;
	}
	else
	{
		*stk = newentry;
		(*stk)->next = NULL;
	}
	return ;
}

void	ft_stackstart(t_stk **stka, char **args)
{
	t_stk			*entry;
	unsigned int	counter;

	counter = 0;
	while (args[counter])
	{
		entry = ft_createentry(ft_atoi(args[counter]));
		ft_addentryback(stka, entry);
		counter++;
	}
	ft_freeptr(args);
	ft_simplify(stka);
	return ;
}
