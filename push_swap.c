#include "push_swap.h"

char	**ft_getnbrs(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	char	**args;
	int	counter;

	if (argc < 2)
		exit(0);
	args = ft_getnbrs(argc, argv);
	printf("%d\n", ft_ptrlen(args));
	counter = 0;
	while(args[counter])
	{
		printf("%s\n", args[counter]);
		counter++;
	}
	ft_isvalid(args);
	printf("valid\n");
	ft_freeptr(args);
	return (0);
}