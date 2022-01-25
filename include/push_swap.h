#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
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
t_stk	**ft_stackstart(t_stk **stka, char **args);

#endif