/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:33:35 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/07 18:18:40 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "libft.h"
# include "parser.h"

# define FINISHED 0x3F

typedef enum e_element
{
	e_south,
	e_north,
	e_west,
	e_east,
	e_floor,
	e_ceiling
}	t_element;

int		parser_map(t_map *map, int fd);
int		parser_retrieve_grid(t_list **list, int fd);
int		parser_validate_grid(t_map *map);
int		parser_textures(t_map *map, int fd);
void	set_flag(int *status, t_element element);
int		has_flag(int status, t_element element);
int		is_finished(int status);
void	skip_spaces(char **str);
void	free_array(char **array);

#endif
