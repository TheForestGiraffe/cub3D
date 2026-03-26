/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/26 17:56:59 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "game.h"
#include "mlx_wrapper.h"

static void	model_load(t_game *game, t_map *map)
{
	
}

static void	player_load(t_game *game, t_map *map)
{
	game->player.x = map->player.x + 0.5;
	game->player.y = map->player.y + 0.5;
	if (map->player.direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
		
	}
	else if (map->player.direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (map->player.direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

static void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx.width = 860;
	game->mlx.height = 640;
}

int	game_setup(t_game *game, t_map *map)
{
	game_init(game);
	if (mlx_setup(game))
		return (1);
	model_load(game, map);
	player_load(game, map);
	return (0);
}
