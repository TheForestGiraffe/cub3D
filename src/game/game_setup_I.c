/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_I.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/26 21:31:52 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "game.h"
#include "mlx_wrapper.h"

static void	model_load(t_game *game, t_map *map)
{
	(void)game;
	(void)map;
}

static void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx.width = 860;
	game->mlx.height = 640;
}

int	game_setup(t_game *game, t_map *map)
{
	if (!game || !map)
		return (1);
	game_init(game);
	if (mlx_setup(game))
		return (1);
	model_load(game, map);
	player_load(game, map);
	return (0);
}
