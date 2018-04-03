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

typedef struct			s_content
{
	int					x;
	int					y;
	int					z;
	int					color;
	struct s_content	*next;
}						t_content;

typedef struct			s_map
{
	int					map_height;
	int					map_width;
	int					size_map;
	int					zoom_x;
	int					zoom_y;
	int					zoom_base;
	int					error;
}						t_map;

#endif