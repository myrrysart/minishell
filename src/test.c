/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:40:45 by jyniemit          #+#    #+#             */
/*   Updated: 2025/06/20 15:55:40 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test(char *line, t_shell *data)
{
	if (!ft_memcmp(line, "exit", 5))
	{
		data->should_exit = 1;
		data->exit_code = EXIT_EXIT;
	}
}
