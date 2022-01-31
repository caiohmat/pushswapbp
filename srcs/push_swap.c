# include "../include/push_swap.h"

void	escreve(t_stk **stka, t_stk **stkb)
{
	t_stk	*temp;

	temp = *stka;
	while (temp)
	{
		printf("%d ", temp->simple);
		temp = temp->next;
	}
	printf("\n");
	temp = *stkb;
	while (temp)
	{
		printf("%d ", temp->simple);
		temp = temp->next;
	}
	printf("\n");
}

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
	if (ft_stklen(stka) <= 5)
		ft_simplesort(stka, stkb, ft_stklen(stka));
	else
		ft_radix(stka,stkb, ft_stklen(stka));
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
	stka = (t_stk **)malloc(sizeof(t_stk));
	stkb = (t_stk **)malloc(sizeof(t_stk));
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
	escreve(stka, stkb);
	ft_freestk(stka);
	ft_freestk(stkb);
	return (0);
}