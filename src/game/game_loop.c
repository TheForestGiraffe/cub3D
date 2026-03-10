/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:51:05 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/10 20:39:10 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <X11/keysym.h>
#include <X11/X.h>

static int	keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game_destruct(game);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, game_destruct, game);
	mlx_loop(game->mlx);
}
