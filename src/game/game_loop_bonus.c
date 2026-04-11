/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:01:37 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/11 08:50:37 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"
#include "minimap_bonus.h"
#include "mlx.h"
#include "raycaster.h"
#include "player_movement.h"

int	game_loop(void *param)
{
	t_game	*game;
	int		x;

	game = (t_game *)param;
	move_player(game);
	rotate_player(game);
	erase_img(&game->mlx.img, game->mlx.height);
	cast_rays(game);
	render(game);
	render_minimap(game);
	return (0);
}
