/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:24:32 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/06 13:26:36 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_internal.h"
#include "utils.h"
#include <stdlib.h>

static int	check_valid_chars(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->grid[x])
	{
		y = 0;
		while (map->grid[x][y])
		{
			if (!ft_strchr("WENS10 ", map->grid[x][y]))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static int	find_player(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	while (map->grid[x])
	{
		y = 0;
		while (map->grid[x][y])
		{
			if (ft_strchr("WENS", map->grid[x][y]))
			{
				map->player.direction = map->grid[x][y];
				map->player.x = x;
				map->player.y = y;
				map->grid[x][y] = '0';
				count++;
			}
			y++;
		}
		x++;
	}
	return (count != 1);
}

static char	**make_visited_grid(int rows, int cols)
{
	char	**new_grid;
	int		i;

	new_grid = malloc((rows + 1) * sizeof(char *));
	if (!new_grid)
		return (print_error("@parser_validate_grid",
				"Allocation fail new_grid"), NULL);
	ft_memset(new_grid, 0, (rows + 1) * sizeof(char *));
	i = 0;
	while (i < rows)
	{
		new_grid[i] = malloc(cols + 1);
		if (!new_grid[i])
		{
			free_array(new_grid);
			return (print_error("@parser_validate_grid",
					"Allocation fail new_grid[i]"), NULL);
		}
		ft_memset(new_grid[i], 0, cols + 1);
		i++;
	}
	new_grid[i] = NULL;
	return (new_grid);
}

static int	validate_map(t_map *map, char **visited, int x, int y)
{
	if (y < 0 || x < 0 || y >= map->cols || x >= map->rows
		|| map->grid[x][y] == ' ')
		return (1);
	if (map->grid[x][y] == '1' || visited[x][y] == 'v')
		return (0);
	visited[x][y] = 'v';
	if (validate_map(map, visited, x + 1, y)
		|| validate_map(map, visited, x - 1, y)
		|| validate_map(map, visited, x, y + 1)
		|| validate_map(map, visited, x, y - 1))
		return (1);
	return (0);
}

int	parser_validate_grid(t_map *map)
{
	char	**visited;

	if (check_valid_chars(map))
		return (print_error("@parser_validate_grid", "Wrong chars present"), 1);
	if (find_player(map))
		return (print_error("@parser_validate_grid", "Player not found"), 1);
	visited = make_visited_grid(map->rows, map->cols);
	if (!visited)
		return (1);
	if (validate_map(map, visited, map->player.x, map->player.y))
	{
		free_array(visited);
		return (print_error("@parser_validate_grid", "Map is not closed"), 1);
	}
	free_array(visited);
	return (0);
}
