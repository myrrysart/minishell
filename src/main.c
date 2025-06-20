/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:49:28 by jyniemit          #+#    #+#             */
/*   Updated: 2025/06/20 15:53:49 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_cleanup(t_shell **data);

int	main(int argc, char **argv, char **env)
{
	t_shell	*data;

	(void)argc;
	(void)argv;
	data = shell_init(env);
	if (!data)
		return (EXIT_SHELLINITFAIL);
	shell_loop(data);
	return (exit_cleanup(&data));
}

int	exit_cleanup(t_shell **data)
{
	int	exit_code_result;

	exit_code_result = (*data)->exit_code;
	arena_destroy((*data)->arena_pool);
	free(*data);
	return (exit_code_result);
}
