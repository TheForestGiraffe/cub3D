/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:18 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/03 18:21:34 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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
	int				floor_color;
	int				ceiling_color;
	char			**grid;
	int				cols;
	int				rows;
	t_map_player	player;
}					t_map;

int		parser(int argc, char *file, t_map *map);
void	parser_destroy(t_map *map);

#endif
