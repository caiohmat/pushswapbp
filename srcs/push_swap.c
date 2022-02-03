/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:46:04 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/03 19:54:50 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	**ft_getnbrs(int argc, char **argv)
{
	char			**args;
	unsigned int	counter;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = malloc(ft_ptrlen(argv) * (sizeof(char **)));
		counter = 0;
		while (argv[counter + 1])
		{
			args[counter] = ft_strdup(argv[counter + 1]);
			counter++;
		}
		args[counter] = NULL;
	}
	return (args);
}

static void	ft_sort(t_stk **stka, t_stk **stkb)
{
	if (ft_stklen(stka) <= 5)
		ft_simplesort(stka, stkb, ft_stklen(stka));
	else
		ft_radix(stka, stkb, ft_stklen(stka));
	return ;
}

int	main(int argc, char **argv)
{
	char	**args;
	t_stk	**stka;
	t_stk	**stkb;

	if (argc < 2)
		return (0);
	args = ft_getnbrs(argc, argv);
	ft_isvalid(args);
	stka = malloc(sizeof(t_stk **));
	stkb = malloc(sizeof(t_stk **));
	*stka = NULL;
	*stkb = NULL;
	ft_stackstart(stka, args);
	if (!ft_sorted(stka))
	{
		ft_freestk(stka);
		ft_freestk(stkb);
		return (0);
	}
	ft_sort(stka, stkb);
	ft_freestk(stka);
	ft_freestk(stkb);
	return (0);
}
