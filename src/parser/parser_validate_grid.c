/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
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
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (ft_strchr("WENS", map->grid[i][j]))
			{
				map->player.direction = map->grid[i][j];
				map->player.x = j;
				map->player.y = i;
				map->grid[i][j] = '0';
				count++;
			}
			j++;
		}
		i++;
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

static int	validate_map(t_map *map, char **visited, int row, int col)
{
	if (col < 0 || row < 0 || col >= map->cols || row >= map->rows
		|| map->grid[row][col] == ' ')
		return (1);
	if (map->grid[row][col] == '1' || visited[row][col] == 'v')
		return (0);
	visited[row][col] = 'v';
	if (validate_map(map, visited, row + 1, col)
		|| validate_map(map, visited, row - 1, col)
		|| validate_map(map, visited, row, col + 1)
		|| validate_map(map, visited, row, col - 1))
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
	if (validate_map(map, visited, map->player.y, map->player.x))
	{
		free_array(visited);
		return (print_error("@parser_validate_grid", "Map is not closed"), 1);
	}
	free_array(visited);
	return (0);
}
