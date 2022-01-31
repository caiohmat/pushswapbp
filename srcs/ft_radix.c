#include "../include/push_swap.h"

int	ft_numberofbits(t_stk **stka)
{
	t_stk	*temp;
	int		max;
	int		bits;

	temp = *stka;
	bits = 0;
	while (temp)
	{
		if(temp->simple > max || !max)
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

void	ft_radix(t_stk **stka, t_stk **stkb, int len)
{
	t_stk	*temp;
	int		bitcount;
	int		counter;
	int		bitmax;

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
}
