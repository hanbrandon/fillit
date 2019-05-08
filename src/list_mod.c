/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:47:44 by doyang            #+#    #+#             */
/*   Updated: 2019/01/16 20:50:22 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**tet_memalloc(size_t y, size_t x)
{
	char	**ptr;
	size_t	i;

	i = 0;
	ptr = (char **)malloc(sizeof(char *) * (y + 1));
	if (!ptr)
		return (0);
	while (i < y + 1)
	{
		ptr[i] = (char *)malloc(sizeof(char) * (x + 1));
		if (!ptr[i])
			return (0);
		ft_memset(ptr[i], 0, (sizeof(char) * (x + 1)));
		i++;
	}
	return (ptr);
}

void		tet_memcpy(char **dst, char **src, size_t y, size_t x)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void		tet_lstadd(t_tet **alst, t_tet *new)
{
	t_tet *tmp;

	if (!(*alst))
	{
		*alst = new;
		(*alst)->next = NULL;
	}
	else
	{
		tmp = *alst;
		while (((*alst)->next) != NULL)
			*alst = (*alst)->next;
		(*alst)->next = new;
		new->next = NULL;
		*alst = tmp;
	}
}

void		tet_lstfree(t_tet **alst)
{
	t_tet *tmp;

	if (!(*alst) || !alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		free(*alst);
		*alst = tmp;
	}
}

t_tet		*tet_lstnew(char **arr, int alph, int height, int width)
{
	t_tet *freshlink;

	freshlink = (t_tet *)ft_memalloc(sizeof(t_tet));
	if (!freshlink)
		return (NULL);
	if (!arr || !*arr)
	{
		freshlink->content = NULL;
		alph = 0;
	}
	else
	{
		freshlink->content = tet_memalloc((size_t)Y_VAL, (size_t)X_VAL);
		if (!(freshlink->content))
		{
			free(freshlink);
			return (NULL);
		}
		tet_memcpy(freshlink->content, arr, Y_VAL, X_VAL);
	}
	freshlink->width = width;
	freshlink->height = height;
	freshlink->alpha = alph;
	freshlink->next = NULL;
	return (freshlink);
}
