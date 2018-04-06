/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:39:41 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/04 10:39:42 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			check_valid_z(char *str, t_map *map, int *j)
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

void			check_valid_width_map(t_map *map)
{
	int			i;
	int			base;

	i = 0;
	base = map->size_str[0];
	while (map->size_str[i])
	{
		if (base != map->size_str[i])
		{
			ft_putstr("Invalid string in file!\n");
			exit(0);
		}
		i++;
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
	return (0);
}

void			valid_arg(int argc, char **argv, t_map *map)
{
	struct stat	sb;

	stat(argv[1], &sb);
	if (argc != 2)
	{
		ft_putstr("You can use only 2 argument!\n");
		exit(1);
	}
	if (!(S_ISREG(sb.st_mode)))
	{
		ft_putstr("It's not a file!\n");
		exit(1);
	}
	if ((map->fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("Can't open file!\n");
		exit(1);
	}
}

void			check_valid_color(char *str, t_map *map)
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
