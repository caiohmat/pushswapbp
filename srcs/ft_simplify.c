/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:46:01 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 20:44:23 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*ft_ascending(t_stk **stka)
{
	t_stk	*temp;
	t_stk	*lowest;

	temp = *stka;
	lowest = NULL;
	while (temp)
	{
		if ((temp->started == 0) && (!lowest || temp->nbr < lowest->nbr))
			lowest = temp;
		temp = temp->next;
	}
	return (lowest);
}

void	ft_simplify(t_stk **stka)
{
	t_stk				*temp;
	unsigned int		simple;

	simple = 0;
	temp = ft_ascending(stka);
	while (temp)
	{
		temp->simple = simple++;
		temp->started = 1;
		temp = ft_ascending(stka);
	}
	return ;
}
