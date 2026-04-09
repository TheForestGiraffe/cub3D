/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/09 23:30:18 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "game.h"
#include "mlx_wrapper.h"
#include "mlx.h"
#include "raycaster.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx.width = 860;
	game->mlx.height = 640;
	game->rays = malloc(sizeof(t_ray) * game->mlx.width);
	if (!game->rays)
		return (print_error("@game_init", "malloc *rays"), 1);
	ft_bzero(game->rays, sizeof(t_ray) * game->mlx.width);
	game->minimap.tile_size = 8;
	game->minimap.player_size = 4;
	game->minimap.player_color = 0x00FF0000;
	game->minimap.floor_color = 0x00AAAAAA;
	game->minimap.wall_color = 0x00444444;
	return (0);
}

int	game_setup(t_game *game, t_map *map)
{
	if (!game || !map)
		return (1);
	if (game_init(game))
		return (1);
	if (mlx_setup(game))
		return (1);
	if (load_model(game, map))
		return (1);
	load_player(game, map);
	return (0);
}
