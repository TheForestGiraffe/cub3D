/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:32:12 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/03 22:22:17 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_INTERNAL_H
# define RENDERER_INTERNAL_H

# include "game.h"

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
	int	color;
}		t_square;

int	draw_square(t_square *square, t_game *game);
int	put_pixel(int x, int y, t_game *game, unsigned int color);

#endif