/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:24:32 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/25 20:27:36 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

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
				count++;
			}
			y++;
		}
		x++;
	}
	return (count);
}

int	parser_validate_map(t_map *map)
{
	if (check_valid_chars(map))
		return (print_error("@parser_validate_map", "check_valid_chars"), 1);
	if (find_player(map) != 1)
		return (print_error("@parser_validate_map", "find_player"), 1);
	return (0);
}
