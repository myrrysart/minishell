# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 12:54:08 by jyniemit          #+#    #+#              #
#    Updated: 2025/06/19 18:05:51 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./src/
SRC =	$(addprefix $(SRCDIR), \
		main.c \
		shell.c \
		arena.c \
)
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
LIBFTDIR = ./includes/libft/
LIBFT = $(LIBFTDIR)libft.a
INCLUDEDIR = ./includes/
HEADER = $(INCLUDEDIR)minishell.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFTDIR) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFTDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	@make -C $(LIBFTDIR)

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	rm -rf $(BUILDDIR)
	@make -C $(LIBFTDIR) fclean
	rm $(NAME)

re: fclean all

debug: fclean
	@make -C $(LIBFTDIR) debug
	$(MAKE) CFLAGS="$(CFLAGS) -g" all

PHONY: debug fclean clean re all
