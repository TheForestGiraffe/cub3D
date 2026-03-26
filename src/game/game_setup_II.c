/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_II.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:19:33 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/26 21:27:33 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game.h"

static void	set_direction(t_game *game, t_map *map)
{
	if (map->player.direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (map->player.direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (map->player.direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (map->player.direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
}

static void	set_plane(t_game *game, t_map *map)
{
	if (map->player.direction == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;

	}
	else if (map->player.direction == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (map->player.direction == 'E')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (map->player.direction == 'W')
	{
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

void	player_load(t_game *game, t_map *map)
{
	game->player.x = map->player.x + 0.5;
	game->player.y = map->player.y + 0.5;
	set_direction(game, map);
	set_plane(game, map);
}
