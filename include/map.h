/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:18 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 21:00:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map_player
{
	int		x;
	int		y;
	char	direction;
}	t_map_player;

typedef struct s_map
{
	char			*tex_north;
	char			*tex_south;
	char			*tex_west;
	char			*tex_east;
	t_rgb			floor_color;
	t_rgb			ceiling_color;
	char			**grid;
	int				width;
	int				height;
	t_map_player	player;
}					t_map;

void	map_destroy(t_map *map);

#endif
