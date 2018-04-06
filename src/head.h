/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:39:10 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/02 13:39:11 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>

# define HEIGHT 1200
# define WIDTH 1000

typedef struct			s_content
{
	double				x;
	double				y;
	double				z;
	double				color;
}						t_content;

typedef struct			s_map
{
	int					**mass;
	int					**color;
	int					*size_str;
	int					fd;
	char				*file_name;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*image;
	double				absc;
	double				ord;
	int					map_height;
	int					map_width;
	int					size_map;
	double				zoom;
	double				zoom_x;
	double				zoom_y;
	int					error;
	int					center;
	int					nexta;
	int					nexto;
}						t_map;

void					check_valid_z(char *str, t_map *map, int *j);
void					check_valid_color(char *str, t_map *map);
void					check_valid_width_map(t_map *map);
void					display1(t_map *map);
void					display2(t_map *map);
void					calc_values(t_map *map, int z, int ax, int oy);
void					drow_ord(t_map *map, int oy, int z, int color);
void					drow_absc(t_map *map, int oy, int z, int color);
void					draw_line(t_map *map, int nextx, int nexty, int color);
void					search_another_parametrs(char *str, t_map *map,
													int y, int i);
int						count_num_coords(char **str);
int						count_num_coords(char **str);
int						exit_x(void *win_ptr);
void					valid_arg(int argc, char **argv, t_map *map);

#endif
