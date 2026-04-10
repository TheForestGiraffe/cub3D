/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_register_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/10 12:14:55 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "mlx_wrapper_internal.h"
#include "X11/X.h"
#include "X11/keysym.h"

void	mlx_register_hooks(t_game *game)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	mlx_hook(mlx->window, DestroyNotify, 0, on_window_destroy, game);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, on_key_press, game);
	mlx_hook(mlx->window, KeyRelease, KeyReleaseMask, on_key_release, game);
	mlx_loop_hook(mlx->mlx, game_loop, game);
}
