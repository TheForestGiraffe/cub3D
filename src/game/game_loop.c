/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:01:37 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/09 22:56:16 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"
#include "renderer.h"
#include "mlx.h"
#include "raycaster.h"
#include <unistd.h>

int	game_loop(void *param)
{
	t_game	*game;
	t_ray	ray;
	int		screen_x;

	game = (t_game *)param;
	screen_x = 0;
	while (screen_x < game->mlx.width)
	{
		cast_single_ray(game, &ray, screen_x);
		render_stripe(game, &ray, screen_x);
		screen_x++;
	}
	if (draw_minimap(game))
		return (1);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->mlx.img.img, 0, 0);
	return (0);
}
