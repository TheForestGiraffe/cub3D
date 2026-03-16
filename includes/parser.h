/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:18 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 14:32:51 by pecavalc         ###   ########.fr       */
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

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player_start
{
	int		x;
	int		y;
	char	direction;
}	t_player_start;

typedef struct s_level_description
{
	char			*tex_north;
	char			*tex_south;
	char			*tex_west;
	char			*tex_east;
	t_rgb			floor_color;
	t_rgb			ceiling_color;
	t_map			map;
	t_player_start	player_start;
}					t_level_description;

int		parse(int argc, char **argv, t_level_description *level_description);
void	level_description_destroy(t_level_description *level_description);

#endif
