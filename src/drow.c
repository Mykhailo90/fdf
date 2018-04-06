/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:53:54 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/06 16:53:56 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			draw_line(t_map *map, int nextx, int nexty, int color)
{
	double		dx;
	double		dy;
	double		dd;
	int			i;

	dx = (map->absc < nextx) ? nextx - map->absc : map->absc - nextx;
	dy = (map->ord < nexty) ? nexty - map->ord : map->ord - nexty;
	dd = (dx > dy) ? dx : dy;
	i = 0;
	dx = nextx - map->absc;
	dy = nexty - map->ord;
	while (i <= dd)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->absc, map->ord, color);
		map->absc += dx / dd;
		map->ord += dy / dd;
		i++;
	}
}

void			drow_absc(t_map *map, int oy, int z, int color)
{
	map->nexto = ((oy - z) * map->zoom_y) + map->center;
	draw_line(map, map->absc + map->zoom_x, map->nexto, color);
}

void			drow_ord(t_map *map, int oy, int z, int color)
{
	map->nexto = (((oy + 1) - z) * map->zoom_y) + map->center;
	draw_line(map, map->absc, map->nexto, color);
}

int				exit_x(void *win_ptr)
{
	win_ptr = NULL;
	exit(1);
	return (0);
}
