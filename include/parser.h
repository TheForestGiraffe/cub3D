/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:18 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/25 21:43:56 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define FINISHED 0x3F

struct	s_list;

typedef enum e_element
{
	e_south,
	e_north,
	e_west,
	e_east,
	e_floor,
	e_ceiling,
	e_count
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

/* ****************************************************************************/
/*                                  PARSER                                    */
/* ************************************************************************** */

int		parser(int argc, char *file, t_map *map);
int		parser_map(t_map *map, int fd);
int		parser_retrieve_map(struct s_list **list, int fd);
int		parser_validate_map(t_map *map);
int		parser_textures(t_map *map, int fd);
void	parser_destroy(t_map *map);

/* ****************************************************************************/
/*                                   UTILS                                    */
/* ************************************************************************** */

void	set_flag(int *status, t_element element);
int		has_flag(int status, t_element element);
int		is_finished(int status);
void	skip_spaces(char **str);
void	free_array(char **array);
void	print_error(char *file, char *function);

#endif
