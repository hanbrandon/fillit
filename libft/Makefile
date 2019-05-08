# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doyang <doyang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 18:56:55 by doyang            #+#    #+#              #
#    Updated: 2019/01/16 23:05:38 by doyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
CC =			gcc
FLAGS =			-Werror -Wall -Wextra
SRCDIR =		src/
OBJDIR =		obj/
IDIR =			include/
SOURCE =		
OBJ =			$(SOURCE:.c=.o)
OBJCOMP =		$(addprefix $(OBJDIR), $(OBJ))
EXT =			$(IDIR)$(NAME:.a=.h)

#is checker:
SOURCE += ft_isalpha.c
SOURCE += ft_isdigit.c
SOURCE += ft_isalnum.c
SOURCE += ft_isascii.c
SOURCE += ft_isprint.c
SOURCE += ft_isupper.c
SOURCE += ft_islower.c
SOURCE += ft_iswhitespace.c
#memory management
SOURCE += ft_memset.c
SOURCE += ft_bzero.c
SOURCE += ft_memcpy.c
SOURCE += ft_memccpy.c
SOURCE += ft_memmove.c
SOURCE += ft_memchr.c
SOURCE += ft_memcmp.c
SOURCE += ft_memalloc.c
SOURCE += ft_memdel.c
SOURCE += ft_freefail.c
#conversion
SOURCE += ft_toupper.c
SOURCE += ft_tolower.c
SOURCE += ft_atoi.c
SOURCE += ft_itoa.c
#string stuffs
SOURCE += ft_strlen.c
SOURCE += ft_strdup.c
SOURCE += ft_strcpy.c
SOURCE += ft_strncpy.c
SOURCE += ft_strcat.c
SOURCE += ft_strncat.c
SOURCE += ft_strlcat.c
SOURCE += ft_strchr.c
SOURCE += ft_strrchr.c
SOURCE += ft_strstr.c
SOURCE += ft_strnstr.c
SOURCE += ft_strcmp.c
SOURCE += ft_strncmp.c
SOURCE += ft_strnew.c
SOURCE += ft_strdel.c
SOURCE += ft_strclr.c
SOURCE += ft_striter.c
SOURCE += ft_striteri.c
SOURCE += ft_strmap.c
SOURCE += ft_strmapi.c
SOURCE += ft_strequ.c
SOURCE += ft_strnequ.c
SOURCE += ft_strsub.c
SOURCE += ft_strjoin.c
SOURCE += ft_strtrim.c
SOURCE += ft_strsplit.c
SOURCE += ft_countword.c
#print
SOURCE += ft_putchar.c
SOURCE += ft_putstr.c
SOURCE += ft_putnbr.c
SOURCE += ft_putendl.c
SOURCE += ft_putchar_fd.c
SOURCE += ft_putstr_fd.c
SOURCE += ft_putendl_fd.c
SOURCE += ft_putnbr_fd.c
#linked list
SOURCE += ft_lstnew.c
SOURCE += ft_lstdelone.c
SOURCE += ft_lstdel.c
SOURCE += ft_lstadd.c
SOURCE += ft_lstiter.c
SOURCE += ft_lstmap.c

all: $(NAME)

##actual make
$(NAME): $(OBJCOMP)
	@ar rc $(NAME) $(OBJCOMP)
	@ranlib $(NAME)

$(OBJCOMP): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)	

$(OBJDIR)%.o: $(SRCDIR)%.c $(EXT)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(IDIR)

norm:
	@norminette $(SRCDIR) $(IDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
