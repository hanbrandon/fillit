/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:50:18 by doyang            #+#    #+#             */
/*   Updated: 2019/01/16 20:53:40 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define X_VAL	5
# define Y_VAL	5

typedef struct		s_tet
{
	char			**content;
	struct s_tet	*next;
	int				alpha;
	int				width;
	int				height;
}					t_tet;

typedef struct		s_map
{
	char			**maparr;
	struct s_map	*next;
	int				mapsize;
}					t_map;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

int					check_dot_sharp(char **arr);
int					check_side(char **arr);
int					check_val_tet(char **arr);
int					store_tetriminos(int fd, t_tet **tetlist);
int					initiate(char *file, t_tet **tetlist);
char				**tet_memalloc(size_t y, size_t x);
void				tet_memcpy(char **dst, char **src, size_t y, size_t x);
void				tet_lstadd(t_tet **alst, t_tet *new);
t_tet				*tet_lstnew(char **arr, int alph, int height, int width);
void				tet_lstfree(t_tet **alst);
void				tet_error();
void				tet_cut(char **arr, t_tet **tetlist, int alph);
int					tet_cut_left(char **arr);
int					tet_cut_top(char **arr);
int					tet_cut_bottom(char **arr);
int					tet_cut_right(char **arr);
int					check_n_store(char **arr,
									t_tet **tetlist, int alph);
int					get_min_map(t_tet *tetlist);
t_map				*new_map(int size);
int					tet_sqrt(double num);
t_map				*tet_solve(t_tet *blocks);
void				map_print(t_map **finalmap, int size);
int					fit_valid(t_map *solution, t_tet *blocks);
void				tet_mapfree(t_map **alst);
t_coord				*point_new(int y, int x);
int					place(t_tet *tetri, t_map *solution, int y, int x);
void				set_piece(t_tet *tetri,
								t_map *solution, t_coord *coord, int c);

#endif
