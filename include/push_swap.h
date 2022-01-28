#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_stk
{
	int				nbr;
	struct s_stk	*next;
	int				simple;
}					t_stk;

void	ft_isvalid(char **args);
void	ft_freeandexit(char **args);
void	ft_freeptr(char **args);
void	ft_stackstart(t_stk **stka, char **args);
t_stk	*ft_createentry(int nbr);
void ft_simplify(t_stk **stka);
int pa(t_stk **stka, t_stk **stkb);
int pb(t_stk **stka, t_stk **stkb);
int	ft_stklen(t_stk **stk);
void	ft_freestk(t_stk **stk);
int	ft_sorted(t_stk **stka);
int	sa(t_stk **stka);
int	sb(t_stk **stkb);
int ss(t_stk **stka, t_stk **stkb);

#endif