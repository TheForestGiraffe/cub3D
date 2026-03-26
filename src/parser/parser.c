/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 23:46:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/26 23:50:41 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stdlib.h"
#include "string.h"

// STUB PARSER

static char	*grid_rows[] = {
	"111111",
	"100001",
	"101001",
	"1000N1",
	"111111",
	NULL
};

int	parser(int argc, char **argv, t_map *map)
{
	int	i;

	(void)argc;
	(void)argv;
	map->tex_north = "textures/north.xpm";
	map->tex_south = "textures/south.xpm";
	map->tex_west  = "textures/west.xpm";
	map->tex_east  = "textures/east.xpm";
	map->floor_color   = (110 << 16) | (110 << 8) | 110;
	map->ceiling_color = (50  << 16) | (50  << 8) | 200;
	map->cols = 6;
	map->rows = 5;
	map->player.x         = 3;
	map->player.y         = 3;
	map->player.direction = 'N';
	map->grid = malloc(sizeof(char *) * 6);
	if (!map->grid)
		return (1);
	i = 0;
	while (i < 5)
	{
		map->grid[i] = strdup(grid_rows[i]);
		if (!map->grid[i])
			return (1);
		i++;
	}
	map->grid[5] = NULL;
	return (0);
}

void	map_destroy(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid && map->grid[i])
		free(map->grid[i++]);
	free(map->grid);
	map->grid = NULL;
}
