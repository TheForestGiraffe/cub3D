/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:44:57 by pecavalc          #+#    #+#             */
/*   Updated: 2026/04/11 09:16:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_internal_bonus.h"

void	draw_square(t_square *square, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < square->size)
	{
		j = 0;
		while (j < square->size)
		{
			img_put_pixel(game, square->x + j, square->y + i, square->color);
			j++;
		}
		i++;
	}
}
