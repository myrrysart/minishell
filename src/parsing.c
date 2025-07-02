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
	int		e;
	int		temp_len;
	t_token	**tokens;

	splits = num_of_splits(line);
	tokens = allocate_tokens(splits);
	e = 0;
	while(*line)
	{
		if (isdelimeter(*line))
		{
			if (*line == SPACE)
			{
				line++;
				continue ;
			}
			line += copy_delimeter(tokens[e], line);
			e++;
			continue;
		}
		temp_len = ft_strnlen(line);
		tokens[e]->lexeme = (char *) malloc((temp_len + 1) * sizeof(char));
		ft_memcpy(tokens[e]->lexeme, line, temp_len);
		tokens[e]->lexeme[temp_len] = '\0';
		line += temp_len;
		e++;
	}
	return (tokens);
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
		else if (isdelimeter(line[i]) && line[i] != SPACE)
			count++;
		else if ((line[i] == '>' && line[i + 1] == '>') || (line[i] == '<' && line[i + 1] == '<'))
			count--;
		else if (!isdelimeter(line[i]) && line[i + 1] == '\0')
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

int	copy_delimeter(t_token *token, char *line)
{
	int	i;
	int	len;

	len = 1;
	i = 0;
	if ((line[i] == '<' && line[i + 1] == '<')
	|| (line[i] == '>' && line[i + 1] == '>'))
		len = 2;
	token->lexeme = (char *) malloc((len + 1) * sizeof(char));
	while(i < len)
	{
		token->lexeme[i] = line[i];
		i++;
	}
	token->lexeme[i] = '\0';
	return(len);
}

t_token	**allocate_tokens(int n)
{
	t_token	**tokens;
	int	i;

	tokens = (t_token **) malloc((n + 1)* sizeof(t_token *));
	i = 0;
	while (i < n)
	{
		tokens[i] = (t_token *) malloc(1 * sizeof(t_token));
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
