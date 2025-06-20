/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:17 by jyniemit          #+#    #+#             */
/*   Updated: 2025/06/20 15:59:35 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef ARENA_BUFFER
#  define ARENA_BUFFER 10485760
# endif//ARENA_BUFFER
// exit()
# include <stdlib.h>
// uint8_t
# include <stdint.h>
// size_t
# include <stddef.h>
// libft
# include <libft.h>
// readline
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
// sigaction & signals
# include <signal.h>

# define ARG_MAX 2097152

extern volatile sig_atomic_t	g_received_signal;

typedef enum e_exit_num
{
	OK,
	ERROR,
	ERRNOMEM
}	t_exit_num;

typedef struct s_arena
{
	size_t			capacity;
	size_t			size_used;
	void			*heap_memory;
	struct s_arena	*next;
}	t_arena;

typedef struct s_shell
{
	t_exit_num	exit_code;
	int			should_exit;
	t_arena		*arena_pool;
	char		**env;
}	t_shell;

// arena.c
t_arena	*arena_create(size_t capacity);
void	*arena_alloc(t_arena *arena, size_t size);
void	arena_destroy(t_arena *arena);

// shell.c
t_shell	*shell_init(char **env);
void	shell_cleanup(t_shell *shell);
int		shell_loop(t_shell *shell);

// signals.c
void	signal_handler(int signum);
void	setup_signals(void);

#endif//MINISHELL_H
