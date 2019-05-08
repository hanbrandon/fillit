/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetvalidity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:07:48 by doyang            #+#    #+#             */
/*   Updated: 2019/01/10 03:54:39 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_val_tet(char **arr)
{
	if (check_dot_sharp(arr))
	{
		if (check_side(arr))
			return (1);
	}
	return (0);
}

int	check_dot_sharp(char **arr)
{
	int y;
	int x;
	int sharp;
	int dot;

	y = 0;
	sharp = 0;
	dot = 0;
	while (y < Y_VAL)
	{
		x = 0;
		while (x < X_VAL)
		{
			if (arr[y][x] == '#')
				sharp++;
			else if (arr[y][x] == '.')
				dot++;
			x++;
		}
		y++;
	}
	if (sharp == 4 && dot == 12)
		return (1);
	return (0);
}

int	check_side(char **arr)
{
	int y;
	int x;
	int side;

	side = 0;
	y = -1;
	while (++y < Y_VAL - 1)
	{
		x = -1;
		while (++x < X_VAL)
		{
			if (arr[y][x] == '#')
			{
				if (arr[y][x + 1] == '#')
					side++;
				if (arr[y][x - 1] == '#')
					side++;
				if (arr[y + 1][x] == '#')
					side++;
				if ((y - 1 >= 0) && arr[y - 1][x] == '#')
					side++;
			}
		}
	}
	return ((side == 6 || side == 8) ? 1 : 0);
}
