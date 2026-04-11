/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_internal_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:32:12 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/11 08:40:04 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_INTERNAL_BONUS_H
# define MINIMAP_INTERNAL_BONUS_H

# include "game.h"

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
	int	color;
}		t_square;

int	draw_square(t_square *square, t_game *game);

#endif
