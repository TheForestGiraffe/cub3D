/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_register_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/20 16:17:52 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx_wrapper_internal.h"

void	mlx_register_hooks(t_game *game)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	mlx_hook(mlx->window, ON_WINDOW_DESTROY, 0, &on_window_destroy, game);
	mlx_hook(mlx->window, ON_KEY_PRESS, KEY_PRESS_MASK, &on_key_press, game);
	mlx_loop_hook(mlx, &game_loop, game);
}
