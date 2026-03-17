/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:18 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/17 21:24:05 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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

int		parser(int argc, char *file, t_map *map);
void	map_destroy(t_map *map);

#endif
