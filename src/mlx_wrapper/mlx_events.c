/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:07:16 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/20 20:51:47 by pecavalc         ###   ########.fr       */
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
	return (0);
}
