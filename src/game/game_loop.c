/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:01:37 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/11 08:10:34 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"
#include "raycaster.h"
#include "player_movement.h"

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	move_player(game);
	rotate_player(game);
	cast_rays(game);
	render(game);
	return (0);
}