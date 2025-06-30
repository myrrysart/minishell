#include "minishell.h"

//void	parser(char *line)
//{
//	lexer(line);
//}

//void	lexer(char *line)
//{

//}

t_token	**split_to_tokens(char *line)
{
	int		splits;
	int		i;
	int		e;
	int		temp_len;
	t_token	**tokens;

	splits = num_of_splits(line);
	tokens = (t_token **) malloc(splits * sizeof(t_token *));
	e = 0;
	while(*line)
	{
		temp_len = ft_strnlen(line);
		tokens[e]->lexeme = (char *) malloc((temp_len + 1) * sizeof(char));
		ft_memcpy(tokens[e]->lexeme, line, temp_len);
		tokens[e]->lexeme[temp_len + 1] = '\0';
		//put this in to a different function and copy delimeters to their own token .
		if (isdelimeter(*line))
		{

		}
	}
}

int	num_of_splits(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while(line[i])
	{
		if (ft_isalpha(line[i]) && isdelimeter(line[i + 1]))
			count++;
		if (isdelimeter(line[i]) && line[i] != ' ')
			count++;
		if ((line[i] == '>' && line[i + 1] == '>') || (line[i] == '<' && line[i + 1] == '<'))
			count--;
		if (!isdelimeter(line[i]) && line[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

int	isdelimeter(char c)
{
	int		i;
	char	*delimeters;

	delimeters = "|><$' ";
	i = 0;
	while (delimeters[i])
	{
		if (c == delimeters[i])
			return (1);
		i++;
	}
	if (c == 34)
		return (1);
	return (0);
}

int	ft_strnlen(const char *s)
{
	int	count;

	count = 0;
	while (!isdelimeter(s[count]) && s[count])
		count++;
	return (count);
}
