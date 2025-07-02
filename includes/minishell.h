/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:17 by jyniemit          #+#    #+#             */
/*   Updated: 2025/07/02 09:35:28 by skarras          ###   ########.fr       */
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
// boolean values
# include <stdbool.h>

# define ARG_MAX 2097152

extern volatile sig_atomic_t	g_received_signal;

typedef enum e_exit_num
{
	EXIT_OK,
	EXIT_ERROR,
	EXIT_EXIT,
	EXIT_ARENAFAIL,
	EXIT_LINEFAIL,
	EXIT_SHELLINITFAIL
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
	char		*raw_input;
	char		**env;
}	t_shell;

typedef enum e_token_types
{
	PIPE,
	REDIRECTION,
	OTHER
}	t_token_types;

typedef struct s_token
{
	t_token_types	type;
	char			*lexeme;
}	t_token;

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

// parsing.c
void	lexer(char *line);
void	parser(char *line);
int		num_of_splits(char *line);
int		isdelimeter(char c);
t_token	**split_to_tokens(char *line);
int		ft_strnlen(const char *s);
int		copy_delimeter(t_token *token, char *line);
t_token	**allocate_tokens(int n);

#endif//MINISHELL_H
