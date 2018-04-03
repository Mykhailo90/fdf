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

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include "head.h"
#include <stdio.h>

// int				deal_key(int key, void *param)
// {
// 	return (0);
// }

void 			check_valid_z(char *str, t_map *map, int *j)
{
	*j = 0;
	if (str[*j] == '-')
		(*j)++;
	while (str[*j] != ',' && str[*j] != '\0')
	{
		if (!ft_isdigit(str[(*j)++]))
		{
			map->error = 1;
			return ;
		}
	}
}

int				is_input(char ch)
{
	int			i;
	char		*test_str;

	i = 0;
	test_str = "0123456789AaBbCcDdEeFf\0";
	while (test_str[i] != '\0')
	{
		if (test_str[i] == ch)
			return (1);
		i++;
	}
	return 0;
}

void 			check_valid_color(char *str, t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((str[i] != '0' && str[i + 1] != 'x') || str[i + 2] == '\0')
	{
		map->error = 1;
		return ;
	}
	i += 2;
	while (str[i] != '\0')
	{
		if (!is_input(str[i]) || j > 6)
		{
			map->error = 1;
			return ;
		}
		i++;
		j++;
	}
}

void			search_color(char *str, t_content **point, t_map *map)
{
	check_valid_color(str, map);
	if (map->error != 1)
		(*point)->color = ft_atoi_base(str + 2, 16);
}

void			search_another_parametrs(char *str, t_content **point,
																t_map *map)
{
	int			j;

	check_valid_z(str, map, &j);
	if (map->error == 1)
		return ;
	(*point)->z = ft_atoi(str);
	if (str[j] == ',')
		search_color(&str[j + 1], point, map);
	else
		(*point)->color = 0xC0C0C0;
}

void			imput_in_list(t_content **point, t_map *map, char **str, int y)
{
	int 		i;

	i = 0;

	while (str[i])
	{
		(*point)->x = i;
		(*point)->y = y;
		search_another_parametrs(str[i], point, map);
		if (map->error == 1)
		{
			ft_putstr("Invalid map!\n");
			exit(1);
		}
		(*point)->next = ft_memalloc(sizeof(t_content));
		*point = (*point)->next;
		(*point)->next = NULL;
		i++;
	}
	map->size_map += i;
}

t_content		*make_content(t_map *map, int fd)
{
	t_content	*head_list;
	t_content	*point;
	char		*line;
	int			y;
	int			x;
	char		**str;

	y = 0;
	x = 0;
	point = ft_memalloc(sizeof(t_content));
	point->next = NULL;
	head_list = point;
	while (get_next_line(fd, &line))
	{
		str = ft_strsplit(line , ' ');
		imput_in_list(&point, map, str, y);
		y++;
	}
	map->map_height = y;
	return (head_list);
}

int				main(int argc, char **argv)
{
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	t_content	*point;
	t_content	*head;
	t_map		*map;

	map = ft_memalloc(sizeof(t_map));
	map->zoom_base = 50;
	map->zoom_x = map->zoom_base;
	map->zoom_y = map->zoom_base;
	//map->size_map = 0;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("Invalid file!\n");
		return (0);
	}
	point = make_content(map, fd);
	head = point;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1200, 800, argv[1]);
	while (point)
	{	
		mlx_pixel_put(mlx_ptr, win_ptr, point->x + map->zoom_x + 50,
						point->y + map->zoom_y + 50, point->color);
		if (point->next && point->next->x > point->x)
			{
				map->zoom_x += 50;
			}
		else
		{
			map->zoom_x = map->zoom_base;
			map->zoom_y += 50;
		}
		point = point->next;
	}
	//mlx_key_hook(win_ptr, deal_key, (void *)70);
	//mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF);
	mlx_loop(mlx_ptr);
	return (0);
}









