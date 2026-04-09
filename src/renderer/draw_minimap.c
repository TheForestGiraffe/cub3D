/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:16:50 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/03 23:24:04 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "renderer_internal.h"
#include <stdio.h>

static t_square	*select_square(char grid_tile, t_square *wall, t_square *floor)
{
	if (grid_tile == '0')
		return (floor);
	if (grid_tile == '1')
		return (wall);
	return (NULL);
}

static int	draw_walls_and_floor(t_square *wall, t_square *floor, t_game *game)
{
	int			i;
	int			j;
	t_square	*square;

	i = 0;
	while (i < game->model.rows)
	{
		j = 0;
		while (j < game->model.cols)
		{
			square = select_square(game->model.grid[i][j], wall, floor);
			if (square)
			{
				square->x = j * game->minimap.tile_size;
				square->y = i * game->minimap.tile_size;
				if (draw_square(square, game))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	draw_player(t_game *game)
{
	t_square	player;

	player.x = (int)(game->player.x * game->minimap.tile_size)
		- (game->minimap.player_size / 2);
	player.y = (int)(game->player.y * game->minimap.tile_size)
		- (game->minimap.player_size / 2);
	player.size = game->minimap.player_size;
	player.color = game->minimap.player_color;
	if (draw_square(&player, game))
		return (1);
	return (0);
}

int	draw_minimap(t_game *game)
{
	t_square	wall;
	t_square	floor;

	ft_bzero(&wall, sizeof(t_square));
	wall.size = game->minimap.tile_size;
	wall.color = game->minimap.wall_color;
	ft_bzero(&floor, sizeof(t_square));
	floor.size = game->minimap.tile_size;
	floor.color = game->minimap.floor_color;
	if (draw_walls_and_floor(&wall, &floor, game))
		return (1);
	if (draw_player(game))
		return (1);
	return (0);
}
