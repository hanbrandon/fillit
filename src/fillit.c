/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:41:27 by doyang            #+#    #+#             */
/*   Updated: 2019/01/16 22:52:57 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		store_tetriminos(int fd, t_tet **tetlist)
{
	char	**arr;
	int		readval;
	int		y;
	int		alph;
	int		tmpread;

	arr = tet_memalloc(Y_VAL, X_VAL);
	readval = 1;
	alph = -1;
	while (readval)
	{
		y = -1;
		tmpread = readval;
		while (++y < (Y_VAL - 1) && readval)
		{
			readval = read(fd, arr[y], (X_VAL * sizeof(char)));
			if ((readval != 5 && y < 4 && y > 0) || (arr[y][X_VAL - 1] != '\n')
				|| (readval == 0 && tmpread == 1))
				tet_error();
		}
		if (!check_n_store(arr, tetlist, ++alph))
			tet_error();
		readval = read(fd, arr[0], 1);
	}
	return (0);
}

int		check_n_store(char **arr, t_tet **tetlist, int alph)
{
	if (alph >= 26 || alph < 0)
		tet_error();
	if (check_val_tet(arr))
		tet_cut(arr, tetlist, alph);
	else
	{
		tet_lstfree(tetlist);
		return (0);
	}
	return (1);
}

int		initiate(char *file, t_tet **tetlist)
{
	int fd;
	int storeval;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	storeval = store_tetriminos(fd, tetlist);
	if (storeval == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

void	tet_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}

int		main(int argc, char **argv)
{
	t_tet	*tetlist;
	t_map	*solution;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		exit(-1);
	}
	if (initiate(argv[1], &tetlist) == -1)
		tet_error();
	solution = tet_solve(tetlist);
	map_print(&solution, solution->mapsize);
	return (0);
}
