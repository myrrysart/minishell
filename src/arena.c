/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:10:24 by jyniemit          #+#    #+#             */
/*   Updated: 2025/06/19 17:53:21 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*arena_alloc(t_arena *arena, size_t size);
void	arena_destroy(t_arena *arena);


t_arena	*arena_create(size_t capacity)
{
	t_arena	*allocation;

	allocation = malloc(sizeof(t_arena));
	if (!allocation)
		return (NULL);
	allocation->capacity = capacity;
	allocation->size_used = 0;
	allocation->heap_memory = malloc(capacity);
	if (!allocation->heap_memory)
		return (NULL);
	allocation->next = NULL;
	return (allocation);
}

void	arena_destroy(t_arena *arena)
{
	t_arena	*current;
	t_arena	*next;

	current = arena;
	while (current)
	{
		next = current->next;
		free(current->heap_memory);
		free(current);
		current = next;
	}
}

void	*arena_alloc(t_arena *arena, size_t size)
{
	void	*result;

	if (arena->size_used + size > arena->capacity)
		return (NULL);
	result = (char *)arena->heap_memory + arena->size_used;
	arena->size_used += size;
	return (result);
}
