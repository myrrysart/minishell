/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:49:28 by jyniemit          #+#    #+#             */
/*   Updated: 2025/07/02 10:40:12 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char	*arg;
	t_token	**tokens;
	int		i;

	//parser(argv[1]);
	arg = readline(NULL);
	tokens = split_to_tokens(arg);
	i = 0;
	while (tokens[i])
	{
		printf("%s\n", tokens[i]->lexeme);
		i++;
	}
	return (0);
}
