/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:10:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/02 19:11:19 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parser_internal.h"
#include <stdlib.h>

void	parser_destroy(t_map *map)
{
	int	i;

	i = 0;
	while (i < e_floor)
	{
		free(map->textures[i]);
		i++;
	}
	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	get_next_line(-1);
}
