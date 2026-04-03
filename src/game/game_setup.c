/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/03 23:25:20 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "game.h"
#include "mlx_wrapper.h"
#include "mlx.h"

static void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx.width = 860;
	game->mlx.height = 640;
	game->minimap.tile_size = 8;
	game->minimap.player_size = 4;
	game->minimap.player_color = 0x00FF0000;
	game->minimap.floor_color = 0x00AAAAAA;
	game->minimap.wall_color = 0x00444444;
}

int	game_setup(t_game *game, t_map *map)
{
	if (!game || !map)
		return (1);
	game_init(game);
	if (mlx_setup(game))
		return (1);
	if (load_model(game, map))
		return (1);
	load_player(game, map);
	return (0);
}
