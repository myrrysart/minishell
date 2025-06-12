# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 12:54:08 by jyniemit          #+#    #+#              #
#    Updated: 2025/06/12 11:17:18 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./src/
SRC =	$(addprefix $(SRCDIR), \
		main.c \
)
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
LIBFTDIR = ./include/libft/
LIBFT = $(LIBFTDIR)libft.a
INCLUDEDIR = ./include/
HEADER = $(INCLUDEDIR)minishell.h

all: $(NAME)

$(NAME): :$(LIBFT) $(OBJS)

$(OBJS): 
$(OBJDIR):
	mkdir -P $(OBJDIR)

re: fclean all

fclean: clean
	rm -rf $(BUILDDIR)
	@make -C $(LIBFTDIR) fclean

debug: fclean
	@make -C $(LIBFTDIR) debug
	$(MAKE) CFLAGS="$(CFLAGS) -g" all

PHONY: debug fclean clean re all
