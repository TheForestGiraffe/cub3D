/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:01:37 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/09 00:12:54 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "renderer.h"
#include "mlx.h"
#include "raycaster.h"
#include <unistd.h>

int	game_loop(void *param)
{
	t_game	*game;
	t_ray	*rays;

	game = (t_game *)param;
	rays = cast_rays(game);
	if (!rays)
		return (1);
	if (draw_minimap(game))
	{
		free (rays);
		return (1);
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->mlx.img.img, 0, 0);
	free(rays);
	return (0);
}
