# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doyang <doyang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 00:09:35 by doyang            #+#    #+#              #
#    Updated: 2019/01/16 23:06:43 by doyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit
CC =		gcc
FLAGS =		-Werror -Wall -Wextra
SRCDIR =	src/
OBJDIR =	obj/
IDIR =		includes/
SOURCE =	fillit.c \
			list_mod.c \
			tetvalidity.c \
			tetcut.c \
			tetmap.c \
			solve.c
OBJ =		$(SOURCE:.c=.o)
OBJCOMP =	$(addprefix $(OBJDIR), $(OBJ))
EXT =		$(IDIR)fillit.h
LIBINC =	libft/include/
LFLAGS =	-L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJCOMP) | lib
	@$(CC) $(FLAGS) -o $(NAME) $(OBJCOMP) $(LFLAGS)

$(OBJCOMP): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(EXT)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(LIBINC) -I $(IDIR)

lib:
	@make -C ./libft

clean:
	@rm -rf obj/
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all
