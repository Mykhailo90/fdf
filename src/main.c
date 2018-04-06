/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:11:16 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/02 11:11:17 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void					imput_in_list(t_map *map, char **str, int y)
{
	int					i;

	i = 0;
	map->map_width = 0;
	map->zoom_x = 20;
	map->zoom_y = 20;
	map->center = 200;
	map->map_width = map->size_str[0];
	map->mass[y] = ft_memalloc(sizeof(int) * map->map_width + 1);
	map->color[y] = ft_memalloc(sizeof(int) * map->map_width + 1);
	while (str[i])
	{
		search_another_parametrs(str[i], map, y, i);
		if (map->error == 1)
		{
			ft_putstr("Invalid map!\n");
			exit(1);
		}
		i++;
	}
	map->size_map += i;
}

void					make_content(t_map *map)
{
	char				*line;
	int					y;
	char				**str;

	y = 0;
	while (get_next_line(map->fd, &line))
	{
		y++;
		ft_strdel(&line);
	}
	close(map->fd);
	map->map_height = y;
	y = 0;
	map->mass = ft_memalloc(sizeof(int *) * map->map_height + 1);
	map->color = ft_memalloc(sizeof(int *) * map->map_height + 1);
	map->size_str = ft_memalloc(sizeof(int *) * map->map_height + 1);
	map->fd = open(map->file_name, O_RDONLY);
	while (get_next_line(map->fd, &line))
	{
		str = ft_strsplit(line, ' ');
		map->size_str[y] = count_num_coords(str);
		imput_in_list(map, str, y);
		ft_strdel(&line);
		y++;
	}
}

void					dell_leaks(t_map *map)
{
	int					i;

	i = 0;
	while (i < map->map_height)
	{
		free(map->mass[i]);
		i++;
	}
	free(map->mass);
	i = 0;
	while (i < map->map_height)
	{
		free(map->color[i]);
		i++;
	}
	free(map->color);
	free(map->size_str);
	free(map->file_name);
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map->image);
}

static int				ft_key(int key, t_map *map)
{
	if (key == 53)
	{
		dell_leaks(map);
		exit(0);
	}
	else if (key == 78)
	{
		map->zoom_x -= 3;
		map->zoom_y -= 2;
	}
	else if (key == 69)
	{
		map->zoom_x += 3;
		map->zoom_y += 2;
	}
	else if (key == 125)
		map->center += 20;
	else if (key == 126)
		map->center -= 20;
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->image, 0, 0);
	display1(map);
	display2(map);
	return (0);
}

int						main(int argc, char **argv)
{
	t_map				m;
	t_map				*map;

	map = &m;
	valid_arg(argc, argv, map);
	map->file_name = ft_memalloc(sizeof(char) * ft_strlen(argv[1]));
	ft_strcpy(map->file_name, argv[1]);
	make_content(map);
	close(map->fd);
	check_valid_width_map(map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, argv[1]);
	map->image = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	display1(map);
	display2(map);
	mlx_key_hook(map->win_ptr, ft_key, map);
	mlx_hook(map->win_ptr, 17, 1L << 17, exit_x, map->mlx_ptr);
	mlx_loop(map->mlx_ptr);
	return (0);
}
