/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:49:28 by jyniemit          #+#    #+#             */
/*   Updated: 2025/06/19 17:31:32 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int	main(int argc, char **argv, char **env)
{
	t_shell *data;

	(void)argc;
	(void)argv;
	data = shell_init(env);
	shell_loop(data);
	return (data->exit_code);
}
