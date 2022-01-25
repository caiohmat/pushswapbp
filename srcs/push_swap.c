#include "push_swap.h"

static char	**ft_getnbrs(int argc, char **argv)
{
	char	**args;
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
	if (stklen(stka) <= 5)
		ft_sort_short(stka, stkb);
	else
		ft_sort_long(stka, stkb);
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
	stka = NULL;
	stkb = NULL;
	ft_stackstart(stka, args);
	if (!ft_sorted)
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