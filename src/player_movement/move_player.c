/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:28:46 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/10 20:13:35 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "move_internal.h"

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_x * game->player.ctrl.move_speed;
	new_y = game->player.y + game->player.dir_y * game->player.ctrl.move_speed;
	if (is_valid_x(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_y(game, game->player.x, new_y))
		game->player.y = new_y;
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_x * game->player.ctrl.move_speed;
	new_y = game->player.y - game->player.dir_y * game->player.ctrl.move_speed;
	if (is_valid_x(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_y(game, game->player.x, new_y))
		game->player.y = new_y;
}

static void	move_left(t_game *game)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -game->player.dir_y;
	perp_y = game->player.dir_x;
	new_x = game->player.x - perp_x * game->player.ctrl.move_speed;
	new_y = game->player.y - perp_y * game->player.ctrl.move_speed;
	if (is_valid_x(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_y(game, game->player.x, new_y))
		game->player.y = new_y;
}

static void	move_right(t_game *game)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -game->player.dir_y;
	perp_y = game->player.dir_x;
	new_x = game->player.x + perp_x * game->player.ctrl.move_speed;
	new_y = game->player.y + perp_y * game->player.ctrl.move_speed;
	if (is_valid_x(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_y(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	move_player(t_game *game)
{
	if (game->player.ctrl.move_forward)
		move_forward(game);
	if (game->player.ctrl.move_backward)
		move_backward(game);
	if (game->player.ctrl.move_left)
		move_left(game);
	if (game->player.ctrl.move_right)
		move_right(game);
}
