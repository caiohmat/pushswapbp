/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:45:40 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/03 16:54:34 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stk
{
	int				nbr;
	int				started;
	struct s_stk	*next;
	unsigned int	simple;
}					t_stk;

void				ft_isvalid(char **args);
void				ft_freeandexit(char **args);
void				ft_freeptr(char **args);
void				ft_stackstart(t_stk **stka, char **args);
t_stk				*ft_createentry(int nbr);
void				ft_simplify(t_stk **stka);
int					pa(t_stk **stka, t_stk **stkb);
int					pb(t_stk **stka, t_stk **stkb);
unsigned int		ft_stklen(t_stk **stk);
void				ft_freestk(t_stk **stk);
int					ft_sorted(t_stk **stka);
int					sa(t_stk **stka);
int					sb(t_stk **stkb);
int					ss(t_stk **stka, t_stk **stkb);
int					ra(t_stk **stka);
int					rb(t_stk **stkb);
int					rr(t_stk **stka, t_stk **stkb);
int					rra(t_stk **stka);
int					rrb(t_stk **stkb);
int					rrr(t_stk **stka, t_stk **stkb);
t_stk				*ft_findlast(t_stk	*entry);
void				ft_radix(t_stk **stka, t_stk **stkb, unsigned int len);
int					ft_findmin(t_stk **stka);
void				ft_simplesort(t_stk **stka, t_stk **stkb, unsigned int len);

#endif