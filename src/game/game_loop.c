/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:01:37 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/10 12:50:34 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "renderer.h"
#include "mlx.h"
#include "raycaster.h"
#include "player_movement.h"
#include <stdlib.h>
#include <stdio.h>

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	move_player(game);
	erase_img(&game->mlx.img, game->mlx.height);
	cast_rays(game);
	if (draw_minimap(game))
	{
		game_destroy(game);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->mlx.img.img, 0, 0);
	return (0);
}
