/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:18 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/02 20:00:12 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

struct	s_list;

typedef enum e_element
{
	e_south,
	e_north,
	e_west,
	e_east,
	e_floor,
	e_ceiling
}	t_element;

typedef struct s_map_player
{
	int		x;
	int		y;
	char	direction;
}	t_map_player;

typedef struct s_map
{
	char			*textures[4];
	int				color[2];
	char			**grid;
	int				width;
	int				height;
	t_map_player	player;
}	t_map;

int		parser(int argc, char *file, t_map *map);
void	parser_destroy(t_map *map);

#endif
