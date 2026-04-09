/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:01:37 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/09 23:42:21 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "renderer.h"
#include "mlx.h"
#include "raycaster.h"
#include <stdlib.h>

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
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
