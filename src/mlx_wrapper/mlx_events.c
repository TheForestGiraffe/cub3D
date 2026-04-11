/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:07:16 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/11 08:57:33 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx_wrapper_internal.h"
#include <X11/keysym.h>
#include <stdlib.h>

int	on_window_destroy(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game_destroy(game);
	exit(0);
	return (0);
}

int	on_key_press(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == XK_Escape)
	{
		game_destroy(game);
		exit(0);
	}
	if (key == XK_a)
		game->player.ctrl.move_left = true;
	if (key == XK_d)
		game->player.ctrl.move_right = true;
	if ((key == XK_w))
		game->player.ctrl.move_forward = true;
	if ((key == XK_s))
		game->player.ctrl.move_backward = true;
	if (key == XK_Left)
		game->player.ctrl.turn_left = true;
	if (key == XK_Right)
		game->player.ctrl.turn_right = true;
	return (0);
}

int	on_key_release(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == XK_a)
		game->player.ctrl.move_left = false;
	if (key == XK_d)
		game->player.ctrl.move_right = false;
	if ((key == XK_w) || (key == XK_Up))
		game->player.ctrl.move_forward = false;
	if ((key == XK_s) || (key == XK_Down))
		game->player.ctrl.move_backward = false;
	if (key == XK_Left)
		game->player.ctrl.turn_left = false;
	if (key == XK_Right)
		game->player.ctrl.turn_right = false;
	return (0);
}
