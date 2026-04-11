/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:44:57 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/11 08:40:31 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_internal_bonus.h"
#include "render.h"

int	draw_square(t_square *square, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < square->size)
	{
		j = 0;
		while (j < square->size)
		{
			if (img_put_pixel(game, square->x + j, square->y + i, square->color))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
