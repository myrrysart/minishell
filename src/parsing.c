#include "../includes/Custom_Libft/libft.h"

void	lexer(char *line);

void	parser(char *line)
{
	lexer(line);
}

void	lexer(char *line)
{
	char **split;
	int		i;

	i = 0;
	split = ft_split(line, ',');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	(void)argc;

	parser(argv[1]);
	return 0;
}
