/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:30:35 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/10 17:04:14 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:28:46 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/10 16:29:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

static void	turn_left(t_game *game)
{
	double	theta;
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	theta = -game->player.ctrl.rot_speed;
	old_dir_x = game->player.dir_x;
	old_dir_y = game->player.dir_y;
	game->player.dir_x = old_dir_x * cos(theta) - old_dir_y * sin(theta);
	game->player.dir_y = old_dir_x * sin(theta) + old_dir_y * cos(theta);
	old_plane_x = game->player.plane_x;
	old_plane_y = game->player.plane_y;
	game->player.plane_x = old_plane_x * cos(theta) - old_plane_y * sin(theta);
	game->player.plane_y = old_plane_x * sin(theta) + old_plane_y * cos(theta);
}

static void	turn_right(t_game *game)
{
	double	theta;
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	theta = game->player.ctrl.rot_speed;
	old_dir_x = game->player.dir_x;
	old_dir_y = game->player.dir_y;
	game->player.dir_x = old_dir_x * cos(theta) - old_dir_y * sin(theta);
	game->player.dir_y = old_dir_x * sin(theta) + old_dir_y * cos(theta);
	old_plane_x = game->player.plane_x;
	old_plane_y = game->player.plane_y;
	game->player.plane_x = old_plane_x * cos(theta) - old_plane_y * sin(theta);
	game->player.plane_y = old_plane_x * sin(theta) + old_plane_y * cos(theta);
}

void	rotate_player(t_game *game)
{
	if (game->player.ctrl.turn_left)
		turn_left(game);
	if (game->player.ctrl.turn_right)
		turn_right(game);
}
