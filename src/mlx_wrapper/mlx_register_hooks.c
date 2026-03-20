/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_register_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/19 17:00:09 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx_wrapper_internal.h"

void	mlx_register_hooks(t_game *game)
{
	mlx_hook(game->mlx.window, ON_WINDOW_DESTROY, 0, &on_window_destroy, game);
	mlx_hook(game->mlx.window, ON_KEY_PRESS, KEY_PRESS_MASK, 
		&handle_on_key_press, app);
	mlx_hook(game->mlx.window, ON_BUTTON_PRESS, BUTTON_PRESS_MASK, 
		&handle_on_button_press, app);
	mlx_hook(game->mlx.window, ON_BUTTON_RELEASE, BUTTON_RELEASE_MASK, 
		&handle_on_button_release, app);
	mlx_hook(game->mlx.window, ON_MOUSE_MOVE, MOUSE_MOVE_MASK, 
		&handle_on_mouse_move, app);
	mlx_loop_hook(app->mlx, &handle_auto_rotate_model, app);
}
