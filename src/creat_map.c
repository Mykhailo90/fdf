/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:58:37 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/06 16:58:39 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void				calc_values(t_map *map, int z, int ax, int oy)
{
	map->absc = (ax * map->zoom_x) + map->center;
	map->ord = ((oy - z) * map->zoom_y) + map->center;
}

void				display1(t_map *map)
{
	int				oy;
	int				ax;

	oy = 0;
	while (oy < map->map_height)
	{
		ax = 0;
		while (ax < map->map_width)
		{
			calc_values(map, map->mass[oy][ax], ax, oy);
			if (map->absc < WIDTH && map->ord < HEIGHT)
			{
				mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->absc,
								map->ord, map->color[oy][ax]);
				if (oy + 1 < map->map_height)
					drow_ord(map, oy, map->mass[oy + 1][ax],
												map->color[oy + 1][ax]);
			}
			ax++;
		}
		oy++;
	}
}

void				display2(t_map *map)
{
	int				oy;
	int				ax;

	oy = 0;
	while (oy < map->map_height)
	{
		ax = 0;
		while (ax < map->map_width)
		{
			calc_values(map, map->mass[oy][ax], ax, oy);
			if (map->absc < WIDTH && map->ord < HEIGHT)
			{
				mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->absc,
								map->ord, map->color[oy][ax]);
				if (ax + 1 < map->map_width)
					drow_absc(map, oy, map->mass[oy][ax + 1],
											map->color[oy][ax + 1]);
			}
			ax++;
		}
		oy++;
	}
}
