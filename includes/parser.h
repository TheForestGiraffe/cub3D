/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:18 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/16 13:09:26 by pecavalc         ###   ########.fr       */
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

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}	t_player;

typedef struct s_parsed_model
{
	char		*tex_north;
	char		*tex_south;
	char		*tex_west;
	char		*tex_east;
	t_rgb		floor_color;
	t_rgb		ceiling_color;
	t_map		map;
	t_player	player;
}				t_parsed_model;

t_parsed_model	*parse(int argc, char **argv);
void			parsed_model_destroy(t_parsed_model *parsed_model);

#endif
