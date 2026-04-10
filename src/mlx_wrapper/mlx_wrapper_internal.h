/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:27:27 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/10 12:15:31 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_INTERNAL_H
# define MLX_WRAPPER_INTERNAL_H

# include "game.h"

// mlx_register_hooks.c
void	mlx_register_hooks(t_game *game);

// mlx_events.c
int		on_window_destroy(void *param);
int		on_key_press(int key, void *param);
int		on_key_release(int key, void *param);

#endif
