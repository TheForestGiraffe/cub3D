/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:27:27 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/20 16:09:22 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_INTERNAL_H
# define MLX_WRAPPER_INTERNAL_H

# include "game.h"

typedef enum e_events
{
	ON_WINDOW_DESTROY = 17,
	ON_KEY_PRESS = 2,
	ON_BUTTON_PRESS = 4,
	ON_BUTTON_RELEASE = 5,
	ON_MOUSE_MOVE = 6
}	t_events;

typedef enum e_masks
{
	KEY_PRESS_MASK = 1L << 0,
	BUTTON_PRESS_MASK = 1L<<2,
	BUTTON_RELEASE_MASK = 1L<<3,
	MOUSE_MOVE_MASK = 1L<<6
}	t_masks;

typedef enum e_keys
{
	LEFT_ARROW_PRESS = 65361,
	RIGHT_ARROW_PRESS = 65363,
	UP_ARROW_PRESS = 65362,
	DOWN_ARROW_PRESS = 65364
}	t_keys;

// mlx_register_hooks.c
void	mlx_register_hooks(t_game *game);

// mlx_events.c
void	on_window_destroy(void *param);
int		on_key_press(int key, void *param);

#endif
