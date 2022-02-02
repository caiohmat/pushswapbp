/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:45:54 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 20:24:03 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_numberofbits(t_stk **stka)
{
	t_stk				*temp;
	unsigned int		max;
	int					bits;

	temp = *stka;
	bits = 0;
	max = 0;
	while (temp)
	{
		if (temp->simple > max || !max)
			max = temp->simple;
		temp = temp->next;
	}
	while (max)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

void	ft_radix(t_stk **stka, t_stk **stkb, unsigned int len)
{
	t_stk				*temp;
	int					bitcount;
	unsigned int		counter;
	int					bitmax;

	bitmax = ft_numberofbits(stka);
	bitcount = 0;
	while (bitcount < bitmax)
	{
		counter = 0;
		while (counter < len)
		{
			temp = *stka;
			if (((temp->simple >> bitcount) & 1) == 0)
				pb(stka, stkb);
			else
				ra(stka);
			counter++;
		}
		while (ft_stklen(stkb) != 0)
			pa(stka, stkb);
		bitcount++;
	}
	return ;
}
