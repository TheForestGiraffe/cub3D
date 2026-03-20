/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/20 21:58:32 by pecavalc         ###   ########.fr       */
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
