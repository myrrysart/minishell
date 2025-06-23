/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:17:05 by jyniemit          #+#    #+#             */
/*   Updated: 2025/06/23 08:50:44 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	*shell_init(char **env);
void	shell_cleanup(t_shell *shell);
int		shell_loop(t_shell *shell);

int	shell_loop(t_shell *shell)
{
	char	*line;

	while (!shell->should_exit)
	{
		line = readline("super_bash_bros: ");
		if (!line)
		{
			shell->should_exit = 1;
			shell->exit_code = EXIT_LINEFAIL;
			break ;
		}
		if (*line)
			add_history(line);
		ft_printf("%s was written, this does nothing else yet\n", line);
		test(line, shell);
		shell->raw_input = line;
		free(line);
	}
	return (shell->exit_code);
}

t_shell	*shell_init(char **env)
{
	t_shell	*shell;

	setup_signals();
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->exit_code = 0;
	shell->should_exit = 0;
	shell->arena_pool = arena_create(ARENA_BUFFER);
	if (!shell->arena_pool)
	{
		free(shell);
		return (NULL);
	}
	shell->env = env;
	return (shell);
}
