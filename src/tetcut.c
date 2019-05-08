/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetcut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:35:18 by sahan             #+#    #+#             */
/*   Updated: 2019/01/16 19:38:08 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tet_cut_top(char **arr)
{
	int y;
	int x;
	int top;

	y = 0;
	top = 0;
	while (y < Y_VAL)
	{
		x = 0;
		while (x < X_VAL && arr[y][x] == '.')
		{
			if (x == X_VAL - 2)
				top++;
			x++;
		}
		if (arr[y][x] == '#')
			break ;
		y++;
	}
	return (top);
}

int		tet_cut_bottom(char **arr)
{
	int y;
	int x;
	int bottom;

	y = Y_VAL - 1;
	bottom = 0;
	while (y > 0)
	{
		x = X_VAL - 2;
		while (x >= 0 && arr[y][x] == '.')
		{
			if (x == 0)
				bottom++;
			x--;
		}
		if (arr[y][x] == '#')
			break ;
		y--;
	}
	return (bottom);
}

int		tet_cut_left(char **arr)
{
	int y;
	int x;
	int left;

	x = 0;
	left = 0;
	while (x < X_VAL)
	{
		y = 0;
		while (y < Y_VAL - 1 && arr[y][x] == '.')
		{
			if (y == Y_VAL - 2)
				left++;
			y++;
		}
		if (arr[y][x] == '#')
			break ;
		x++;
	}
	return (left);
}

int		tet_cut_right(char **arr)
{
	int y;
	int x;
	int right;

	x = X_VAL - 2;
	right = 0;
	while (x >= 0)
	{
		y = Y_VAL - 2;
		while (y >= 0 && arr[y][x] == '.')
		{
			if (y == 0)
				right++;
			y--;
		}
		if (y < 0)
			y++;
		if (arr[y][x] == '#')
			break ;
		x--;
	}
	return (right);
}

void	tet_cut(char **arr, t_tet **tetlist, int alph)
{
	t_tet	*tmplist;
	char	**tmp;
	int		y;
	int		x;

	tmp = tet_memalloc(Y_VAL, X_VAL);
	y = -1;
	while (++y < Y_VAL - 1)
	{
		x = -1;
		while (++x < X_VAL)
		{
			if ((y + tet_cut_top(arr)) >= Y_VAL
				|| (x + tet_cut_left(arr)) >= X_VAL
				|| (Y_VAL - tet_cut_bottom(arr) - tet_cut_top(arr) - 2) < y
				|| (X_VAL - tet_cut_right(arr) - tet_cut_left(arr) - 2) < x)
				tmp[y][x] = '\0';
			else
				tmp[y][x] = arr[y + tet_cut_top(arr)][x + tet_cut_left(arr)];
		}
	}
	tmplist = tet_lstnew(tmp, alph, (Y_VAL - tet_cut_bottom(arr)
		- tet_cut_top(arr) - 1),
		(X_VAL - tet_cut_right(arr) - tet_cut_left(arr) - 1));
	tet_lstadd(tetlist, tmplist);
}
