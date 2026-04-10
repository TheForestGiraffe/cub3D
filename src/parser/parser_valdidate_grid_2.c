/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:56:51 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/10 20:59:43 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"


static int	validate_grid(t_map *map, char **visited, int row, int col)
{
	if (col < 0 || row < 0 || col >= map->cols || row >= map->rows
		|| map->grid[row][col] == ' ')
		return (1);
	if (map->grid[row][col] == '1' || visited[row][col] == 'v')
		return (0);
	visited[row][col] = 'v';
	if (validate_grid(map, visited, row + 1, col)
		|| validate_grid(map, visited, row - 1, col)
		|| validate_grid(map, visited, row, col + 1)
		|| validate_grid(map, visited, row, col - 1))
		return (1);
	return (0);
}

int	check_grid_closure(t_map *map, char **visited)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == '0' && visited[y][x] != 'v')
			{
				if (validate_grid(map, visited, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
