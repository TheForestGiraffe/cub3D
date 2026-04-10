/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:28:46 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/10 12:40:49 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_player(t_game *game)
{
	t_ctrl	*ctrl;

	ctrl = &game->player.ctrl;
	if (ctrl->move_forward)
	{
		game->player.dir_x += 0.5;
		game->player.dir_y += 0.5;
		game->player.plane_x += 0.5;
		game->player.plane_y += 0.5;
	}
	if (ctrl->move_backward)
	{
		game->player.dir_x -= 0.5;
		game->player.dir_y -= 0.5;
		game->player.plane_x -= 0.5;
		game->player.plane_y -= 0.5;
	}
}
