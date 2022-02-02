/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:31 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 20:20:02 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_sorted(t_stk **stka)
{
	t_stk	*temp;

	temp = *stka;
	while (temp && temp->next)
	{
		if (temp->nbr >= temp->next->nbr)
			return (1);
		temp = temp->next;
	}
	return (0);
}

unsigned int	ft_stklen(t_stk **stk)
{
	t_stk			*temp;
	unsigned int	len;

	temp = *stk;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
