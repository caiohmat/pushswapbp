# include "push_swap.h"

void	ft_onlynumbers(char **args)
{
	unsigned int	i;
	unsigned int 	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if ((!ft_isdigit(args[i][j])))
			{
				if (j != 0 || args[i][j] != '-')
					ft_freeandexit(args, '1');
			}
			j++;
		}
		i++;
	}
	return ;
}

void	ft_noduplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				ft_freeandexit(args, '2');
			j++;
		}
		i++;
	}
	return ;
}

void	ft_isvalid(char **args)
{
	ft_onlynumbers(args);
	ft_noduplicates(args);
	return ;
}
