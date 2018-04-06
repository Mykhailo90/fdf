/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:56:01 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/06 16:56:02 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			search_color(char *str, t_map *map, int y, int i)
{
	check_valid_color(str, map);
	if (map->error != 1)
		map->color[y][i] = ft_atoi_base(str + 2, 16);
}

void			search_another_parametrs(char *str, t_map *map, int y, int i)
{
	int			j;

	check_valid_z(str, map, &j);
	if (map->error == 1)
		return ;
	map->mass[y][i] = ft_atoi(str);
	if (str[j] == ',')
		search_color(&str[j + 1], map, y, i);
	else
		map->color[y][i] = 0xC0C0C0;
}

int				count_num_coords(char **str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
